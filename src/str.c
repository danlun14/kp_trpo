#include "str.h"
#include <stdio.h>
#include <string.h>

int dic_init(dictionary* dic, int capacity)
{
    dic->str = calloc(capacity, sizeof(word));
    if (dic->str == NULL) {
        return -1;
    }
    dic->nums = calloc(capacity, sizeof(long int));
    if (dic->nums == NULL) {
        free(dic->str);
        return -1;
    }
    dic->size_s = 0;
    dic->size_n = 0;
    dic->capacity = capacity;
}

int str_to_dic(dictionary* dic, char* s)
{
    if (dic->size_s == dic->capacity) {
        return -1;
    }
    dic->str[dic->size_s].s = s;
    dic->size_s++;
    return 0;
}
int num_to_dic(dictionary* dic, int num)
{
    if (dic->size_n == dic->capacity) {
        return -1;
    }
    dic->nums[dic->size_n] = num;
    dic->size_n++;
    return 0;
}

void dic_free(dictionary* dic)
{
    for (int i = 0; i < dic->size_s; i++) {
        free(dic->str[i].s);
    }
    free(dic->nums);
    free(dic->str);
    free(dic);
}

int symbol_check(char* s)
{
    if (*s == ' ') {
        return 1;
    }
    if (*s == '.') {
        return 1;
    }
    if (*s == '/') {
        return 1;
    }
    if (*s == '_') {
        return 1;
    }
    if (*s == '-') {
        return 1;
    }
    if (*s == '+') {
        return 1;
    }
    if (*s == '=') {
        return 1;
    }
    if (*s == ',') {
        return 1;
    }
    if (*s == '?') {
        return 1;
    }
    if (*s == '!') {
        return 1;
    }
    return 0;
}
int fill_dic(dictionary* dic, FILE* in)
{
    char* c = calloc(1, sizeof(char));
    char* s = calloc(1, sizeof(char));
    int id = 0, check;
    while (fread(c, sizeof(char), 1, in) != 0) {
        check = symbol_check(c);
        printf("%d", check);
        if (check == 0) {
            s[id] = *c;
            id++;
            s = realloc(s, (id + 1) * sizeof(char));
        } else if (id != 0) {
            s[id] = 0;
            id = is_digit(s);
            if (id > 0) {
                num_to_dic(dic, id);
            } else {
                str_to_dic(dic, s);
            }
            id = 0;
            // printf("%s", s);
            s = calloc(1, sizeof(char));
        }
    }
    if (id != 0) {
        id = is_digit(s);
        if (id > 0) {
            num_to_dic(dic, id);
        } else {
            str_to_dic(dic, s);
        }
        s[id] = 0;
    }
    return 0;
}

int scmp(char* str1, char* str2)
{
    if (&str1 == NULL || &str2 == NULL) {
        return -1;
    }
    for (int i = 0; str1[i] != '\0' || str2[i] != '\0'; i++) {
        if (str1[i] != str2[i]) {
            if (str1[i] > str2[i]) {
                return 1;
            } else if ((str1[i] < str2[i])) {
                return 2;
            }
        }
    }
    return 0;
}

void swap_pointers(char** str1, char** str2)
{
    char* tmp;
    tmp = *str1;
    *str1 = *str2;
    *str2 = tmp;
}

void sort_str(dictionary* dic)
{
    int f;
    for (int i = 0; i < dic->size_s; i++) {
        for (f = 0; f < dic->size_s - 1; f++) {
            if (scmp(dic->str[f].s, dic->str[f + 1].s) == 1) {
                swap_pointers(&dic->str[f].s, &dic->str[f + 1].s);
            }
        }
    }
}

void dic_out(FILE* out, dictionary* dic)
{
    for (int i = 0; i < dic->size_s; i++) {
        fprintf(out, "%s\n", dic->str[i].s);
    }
}
int slen(char* s)
{
    if (s == NULL) {
        return -1;
    }
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

long int is_digit(char* s)
{
    if (s == NULL) {
        return -2;
    }
    char* endPtr;
    int len = slen(s);
    long int num = strtol(s, &endPtr, 10);
    if ((endPtr - s) == len) {
        return num;
    }
    return -1;
}

void int_Bubble_sort(dictionary* dic)
{
    int h = dic->nums;
    for (int i = 0; i < h; i++) {
        for (int c = 0; c < h - 1; c++) {
            if (dic->size_n[c] > dic->size_n[c + 1]) {
                swap_int(&dic->size_n[c], &dic->size_n[c + 1]);
            }
        }
    }
}