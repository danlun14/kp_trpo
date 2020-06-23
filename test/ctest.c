#include "ctest.h"
#include "command.h"
#include "sort.h"
#include "stdio.h"
#include "str.h"

CTEST(arithmetic_suite, dic_init)
{
    dictionary dic1;
    int i = dic_init(&dic1, 65655);
    ASSERT_EQUAL(i, 0);
    dic_free(&dic1);
}
