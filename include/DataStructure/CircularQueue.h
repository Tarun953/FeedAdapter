#include <boost/circular_buffer.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition.hpp>
#include <boost/bind.hpp>

template <class T>
class CircularQueue
{
private:
    boost::circular_buffer<T> circularQueue_;
    typename boost::circular_buffer<T>::size_type mUnread_;
    boost::mutex mMutex_; // to acquire lock for the insertion and deletion purposes
    boost::condition mIsNotEmpty_;
    boost::condition mIsNotFull_;

    bool is_not_empty() // This function returns if the circular queue is not empty
    {
        return (mUnread_ > 0);
    }

    bool is_not_full() // This function returns if the circular queue is not full by checking whether the number of unreads is less than the actual capacity of the buffer
    {
        return (mUnread_ < circularQueue_.capacity());
    }

    // Need to block the copy constructor and the = operator to avoid move semantics and faulty equalling operations --> to maintain the integrity of locking variables
    CircularQueue(const CircularQueue &);
    CircularQueue &operator=(const CircularQueue &);

public:
    CircularQueue(typename boost::circular_buffer<T>::size_type _capacity) : mUnread_(0), circularQueue_(_capacity) {};
    ~CircularQueue();

    void push_back(T &&_item) // Taking the reference to the item to put it in the queue efficiently
    {
        // the main task is to write a thread safe push function for the circular queue
        boost::mutex::scoped_lock lock(mMutex_);
        mIsNotFull_.wait(lock, boost::bind(&CircularQueue<typename boost::circular_buffer<T>::value_type>::is_not_full, this)); // bind function is
        circularQueue_.push_back(_item);
        ++mUnread_;
        lock.unlock();
        mIsNotEmpty_.notify_one();
    }

    void pop_front(T *_pItem) // This will pop the first item of the queue and will put it in the item pointed by _pItem
    {
        boost::mutex::scoped_lock lock(mMutex_);
        mIsNotEmpty_.wait(lock, boost::bind(&CircularQueue<typename boost::circular_buffer<T>::value_type>::is_not_empty, this));
        *_pItem = circularQueue_.front();
        circularQueue_.pop_front();
        --mUnread_;
        lock.unlock();
        mIsNotFull_.notify_one();
    }
};
