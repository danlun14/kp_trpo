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

CTEST(arithmetic_suite, num_to_dic)
{
    dictionary dic1;
    dic_init(&dic1, 65655);
    long int num = 50;
    int prev = dic1.size_n;
    prev++;
    num_to_dic(&dic1, num);
    int cur = dic1.size_n;
    ASSERT_EQUAL(prev, cur);
    prev++;
    num_to_dic(&dic1, num);
    cur = dic1.size_n;
    ASSERT_EQUAL(prev, cur);
    prev++;
    num_to_dic(&dic1, num);
    cur = dic1.size_n;
    ASSERT_EQUAL(prev, cur);
    prev++;
    num_to_dic(&dic1, num);
    cur = dic1.size_n;
    ASSERT_EQUAL(prev, cur);
    dic_free(&dic1);
}
