#include "CppUTest/TestHarness.h"
#include "netmask.h"

TEST_GROUP(Netmask)
{
};

TEST(Netmask, Decode)
{
    UNSIGNED_LONGS_EQUAL(0xFFFFFF00, netmask_decode(24));
    UNSIGNED_LONGS_EQUAL(0xFFFFF800, netmask_decode(21));
    UNSIGNED_LONGS_EQUAL(0xFFFF0000, netmask_decode(16));
}
