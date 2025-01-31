#include <list>

template <class T>
class Level
{
private:
    std::list<T>::iterator head_; // Head pointer pointing to the head of the linked list of orders
    std::list<T>::iterator tail_; // Tail pointer pointing to the end of the linked list of orders

    std::map<int, std::list<T>::iterator> orderIdToIteratorMap_; // Storing the pointer to the specific iterator pointer in the order list

public:
    Level();
    ~Level();
};
