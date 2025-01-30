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
    Trade Message specs
    1. STREAM HEADER -> containing the info about stream, total size, sequence number
    2. Message Type: (char 1 byte)
            'T' = Trade Message
    3. Timestamp (In nanoseconds) (LONG 8 bytes) -> To calculate current time --> subtract 01-Jan-1980 00:00:00
    4. Buy Order ID (double 8 bytes) -> Unique order ID for the buy side order
    5. Sell Order ID (double 8 bytes) -> Unique order ID for the sell side order
    6. Token (int 4 bytes) -> Unique contract identifier
    7. Trade Price (int 4 bytes) --> Price of the order (In cents).This field contains the price at which the order is placed. The price is in multiples of the tick size. This should be divided by 10000 for converting into USD.
    7. Quantity (int 4 bytes) --> How much quantity got traded
    8. Checksum (short 2 bytes) --> checksum to check for the validity of the packet
*/

struct TradeMessage
{
public:
    StreamHeader streamHeader_;
    char mssgType
};
