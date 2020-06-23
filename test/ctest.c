#include "ctest.h"
#include "command.h"
#include "sort.h"
#include "stdio.h"
#include "str.h"

/**********sort.h*********/

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

/**********str.h*********/

CTEST(arithmetic_suite, symbol_check)
{
    char q = 'c';
    char n = ' ';
    char n2 = '\n';
    char n3 = '=';
    char q2 = 'G';
    int r1 = symbol_check(&q);
    r1 = symbol_check(&q);
    ASSERT_EQUAL(r1, 0);
    r1 = symbol_check(&n);
    ASSERT_EQUAL(r1, 1);
    r1 = symbol_check(&n2);
    ASSERT_EQUAL(r1, 1);
    r1 = symbol_check(&n3);
    ASSERT_EQUAL(r1, 1);
    r1 = symbol_check(&q2);
    ASSERT_EQUAL(r1, 0);
}

CTEST(arithmetic_suite, swap_str)
{
    dictionary* dic1;
    dic1 = malloc(sizeof(dictionary));
    dic_init(dic1, 65655);
    dictionary* dic2;
    dic2 = malloc(sizeof(dictionary));
    dic_init(dic2, 65655);
    char str[45] = "sun";
    char str2[21] = {'1', 'c', 'd'};
    str_to_dic(dic1, str);
    str_to_dic(dic1, str2);
    str_to_dic(dic2, str);
    str_to_dic(dic2, str2);
    swap_pointers(&dic2->str[1].s, &dic2->str[0].s);
    ASSERT_STR(dic1->str[0].s, dic2->str[1].s);
    ASSERT_STR(dic1->str[1].s, dic2->str[0].s);
}

CTEST(arithmetic_suite, swap_int)
{
    long int a[4];
    a[0] = 40;
    a[1] = 30;
    a[2] = a[0];
    a[3] = a[1];
    swap_int(a, a + 1);
    ASSERT_EQUAL(a[0], a[3]);
    ASSERT_EQUAL(a[2], a[1]);
}

CTEST(arithmetic_suite, scmp)
{
    char* str3 = NULL;
    char str[45] = "sun";
    char str2[21] = {'1', 'c', 'd'};
    int i = scmp(str, str2);
    ASSERT_EQUAL(i, 1);
    i = scmp(str3, str2);
    ASSERT_EQUAL(i, -1);
    i = scmp(str2, str2);
    ASSERT_EQUAL(i, 0);
}

CTEST(arithmetic_suite, slen)
{
    char str[45] = "sun";
    char str2[21] = {'1', 'c', 'd'};
    int i = slen(str);
    int i2 = slen(str2);
    ASSERT_EQUAL(i, 3);
    ASSERT_EQUAL(i2, 3);
}

CTEST(arithmetic_suite, is_digit)
{
    char str[45] = "sun";
    char str2[21] = {'2', '3', '4'};
    int i = is_digit(str);
    ASSERT_EQUAL(i, -1);
    i = is_digit(str2);
    ASSERT_EQUAL(i, 234);
}
