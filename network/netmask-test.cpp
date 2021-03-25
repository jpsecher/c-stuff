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

TEST(Netmask, ToString)
{
    STRCMP_EQUAL("255.255.255.0", netmask_to_str(0xFFFFFF00));
    STRCMP_EQUAL("255.255.248.0", netmask_to_str(0xFFFFF800));
    STRCMP_EQUAL("255.0.0.0", netmask_to_str(0xFF000000));
}

TEST(Netmask, FromString)
{
    UNSIGNED_LONGS_EQUAL(0xFFFFFF00, netmask_from_str("255.255.255.0"));
    UNSIGNED_LONGS_EQUAL(0xFFFFFFFF, netmask_from_str("255.255.255.255"));
    UNSIGNED_LONGS_EQUAL(0xFFFFF800, netmask_from_str("255.255.248.0"));
    UNSIGNED_LONGS_EQUAL(0x0A080800, netmask_from_str("10.8.8.0"));
}

TEST(Netmask, Octet)
{
    UNSIGNED_LONGS_EQUAL(1, octet_str_len(0));
    UNSIGNED_LONGS_EQUAL(2, octet_str_len(10));
    UNSIGNED_LONGS_EQUAL(3, octet_str_len(128));
}
