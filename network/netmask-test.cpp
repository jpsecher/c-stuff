#include "CppUTest/TestHarness.h"
#include "netmask.h"

TEST_GROUP(FirstTestGroup)
{
};

TEST(FirstTestGroup, FirstTest)
{
    UNSIGNED_LONGS_EQUAL(0xFFFFFF00, netmask_decode(24));
}
