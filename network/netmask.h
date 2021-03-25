#if !defined(NETMASK_H)
#define NETMASK_H
#include <stdint.h>

uint32_t netmask_decode(uint8_t bits);
uint8_t netmask_encode(uint32_t mask);
char const * netmask_to_str(uint32_t mask);
uint32_t netmask_from_str(char const *);
uint8_t octet_str_len(uint8_t);

#endif
