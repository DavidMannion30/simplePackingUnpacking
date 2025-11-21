#include <cstdint>      // for cpp
// #include <stdint.h>  // for C
// #include <stdio.h>
// #include <stdlib.h>
#include "packing.h"
#include <iostream>

using namespace std;

uint32_t packed (uint8_t exchange_id, uint8_t message_type, uint16_t order_id)
{
    uint32_t packed = 0;

    //start with moving exchange_id into the top 8 bits (31-24)
    packed |= (uint32_t)exchange_id << 24;

    //shift add and OR the message type from bit 16-23
    packed |= (uint32_t)message_type << 16;

    //add order_id into bottom 16 bits
    packed |= (uint32_t)order_id;
    return packed;
}


void unpack(uint32_t packed, uint8_t &exchange_id, uint8_t &message_type, uint16_t &order_id)
{
    exchange_id = (packed >> 24) & 0xFF;        // get top 8 bits
    message_type = (packed >> 16) & 0xFF;       // get middle 8 bits
    order_id = (packed) & 0xFFFF;               // get remaining 16 bits
}

// uint8_t prints char by default

int main()
{

    uint8_t exchange_id = 15;
    uint8_t message_type = 20;
    uint16_t order_id = 55;

    uint32_t message = packed(exchange_id, message_type, order_id);

    uint8_t exchRec = 0;
    uint8_t idRec = 0;
    uint16_t orderRec = 0;

    unpack(message, exchRec, idRec, orderRec);

    // printf("%d\n", exchRec);
    // printf("%d\n", idRec);
    // printf("%d\n", orderRec);

    cout << (int)exchRec << endl;                // uint8_t is a char, convert back to int to print
    cout << (int)idRec << endl;
    cout << orderRec << endl;

}
