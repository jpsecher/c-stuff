#include "netmask.h"

uint32_t netmask_decode(uint8_t bits)
{
    uint32_t positive_mask = (1 << (32 - bits)) - 1;
    return ~positive_mask;
}

uint8_t netmask_encode(uint32_t mask)
{
    // Only works with GCC
    return __builtin_clz(~mask);
}
