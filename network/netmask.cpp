#include "netmask.h"

uint32_t netmask_decode(uint8_t bits)
{
    uint32_t positive_mask = (1 << (32 - bits)) - 1;
    return ~positive_mask;
}
