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

CTEST(arithmetic_suite, str_to_dic)
{
    dictionary dic1;
    dic_init(&dic1, 65655);
    char str[4] = {'1', 'c', 'd'};
    int prev = dic1.size_s;
    prev++;
    str_to_dic(&dic1, str);
    int cur = dic1.size_s;
    ASSERT_EQUAL(prev, cur);
    prev++;
    str_to_dic(&dic1, str);
    cur = dic1.size_s;
    ASSERT_EQUAL(prev, cur);
    prev++;
    str_to_dic(&dic1, str);
    cur = dic1.size_s;
    ASSERT_EQUAL(prev, cur);
    prev++;
    str_to_dic(&dic1, str);
    cur = dic1.size_s;
    ASSERT_EQUAL(prev, cur);
}
