#include </home/tarun/FeedAdapter/FeedAdapter/include/schema/StreamHeader.hpp>

/*
    Data types
    char - 1 bytes
    short - 2 bytes
    int - 4 bytes
    long - 8 bytes
    double - 8 bytes
*/

/*
    Order Message specs
    1. STREAM HEADER -> containing the info about stream, total size, sequence number
    2. Message Type: (char 1 byte)
            'N' = New Order
            'M' = Order Modification
            'X' = Order Cancellation
    3. Timestamp (In nanoseconds) (LONG 8 bytes) -> To calculate current time --> subtract 01-Jan-1980 00:00:00
    4. Order ID (double 8 bytes) -> Unique order ID assigned to each of the orders
    5. Token (int 4 bytes) -> Unique contract identifier
    6. Price (int 4 bytes) --> Price of the order (In cents).This field contains the price at which the order is placed. The price is in multiples of the tick size. This should be divided by 10000 for converting into USD.
    7. Quantity (int 4 bytes) --> Quantity of the order
    8. Checksum (short 2 bytes) --> checksum to check for the validity of the packet
*/

struct OrderMessage
{
public:
    StreamHeader streamHeader_;
    char mssgType_;
    long timestamp_;
    double orderID_;
    int token_;
    int price_;
    int quantity_;
    // short checkSum_; // Check if this is required by us or not.

    // After getting the orderMessage we have to build the book accordingly.
};
