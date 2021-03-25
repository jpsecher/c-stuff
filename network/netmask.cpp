#include "netmask.h"
#include <stdio.h>
#include <stdlib.h>

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

char const * netmask_to_str(uint32_t mask)
{
    static char buffer[16];
    snprintf(buffer, 16, "%d.%d.%d.%d", (mask >> 24), (mask >> 16) & 0xFF, (mask >> 8) & 0xFF, mask & 0xFF);
    return buffer;
}

uint8_t octet_str_len(uint8_t number)
{
    if (number < 10)
        return 1;
    if (number < 100)
        return 2;
    return 3;
}

uint32_t netmask_from_str(char const * str)
{
    uint8_t index = 0;
    int i1 = atoi(str + index);
    index += octet_str_len(i1) + 1;
    int i2 = atoi(str + index);
    index += octet_str_len(i2) + 1;
    int i3 = atoi(str + index);
    index += octet_str_len(i3) + 1;
    int i4 = atoi(str + index);
    return (i1 << 24) | (i2 << 16) | (i3 << 8) | i4;
}
