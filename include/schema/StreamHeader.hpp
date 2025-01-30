// Following are the properties

/*
    Data types
    char - 1 bytes
    short - 2 bytes
    int - 4 bytes
    long - 8 bytes
    double - 8 bytes
*/

/*
    The stream data is Little endian -> Most significant bit in the end
    Also the structures are packed in pragma pack(1) order which means -> no padding by compiler and 1 column data storage technique
*/

/*
    streamHeader specs:
    short mssg_len -> This is the total size of the packet including the Header and Data (len(streamHeader) + len(streamData))
    short stream_id -> Tells the packet is of which stream
    int seqNo -> increasing sequence number for each of the stream packets (Can be used to check for recovery)
*/
#pragma pack(1)
struct StreamHeader
{
public:
    short mssgLen_;
    short streamId_;
    int seqNo_;
};
