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

CTEST(arithmetic_suite, fill_dic)
{
    char in1[] = "test/test_input/in1";
    char in2[] = "test/test_input/in2";
    char in3[] = "test/test_input/in3";
    FILE* in = fopen(in1, "r");
    dictionary dic1;
    dic_init(&dic1, 65655);
    fill_dic(&dic1, in);
    fclose(in);
    int num = 3;
    int str = 5;
    ASSERT_EQUAL(dic1.size_n, num);
    ASSERT_EQUAL(dic1.size_s, str);
    in = fopen(in2, "r");
    dictionary dic2;
    dic_init(&dic2, 65655);
    fill_dic(&dic2, in);
    fclose(in);
    num = 0;
    str = 0;
    ASSERT_EQUAL(dic2.size_n, num);
    ASSERT_EQUAL(dic2.size_s, str);
    in = fopen(in3, "r");
    dictionary dic3;
    dic_init(&dic3, 65655);
    fill_dic(&dic3, in);
    fclose(in);
    num = 2;
    str = 4;
    ASSERT_EQUAL(dic3.size_n, num);
    ASSERT_EQUAL(dic3.size_s, str);
    dic_free(&dic1);
    dic_free(&dic2);
    dic_free(&dic3);
}
