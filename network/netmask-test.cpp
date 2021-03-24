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

TEST(Netmask, Encode)
{
    UNSIGNED_LONGS_EQUAL(24, netmask_encode(0xFFFFFF00));
    UNSIGNED_LONGS_EQUAL(20, netmask_encode(0xFFFFF400));
    UNSIGNED_LONGS_EQUAL(16, netmask_encode(0xFFFF0000));
}
