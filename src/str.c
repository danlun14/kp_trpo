#include "str.h"
#include <stdio.h>
#include <string.h>

void dic_init(dictionary* dic, int capacity)
{
    dic->str = calloc(capacity, sizeof(word));
    if (dic->str == NULL) {
    }
    dic->size = 0;
    dic->capacity = capacity;
}

int write_in_dic(dictionary* dic, char* s)
{
    if (dic->size == dic->capacity) {
        return -1;
    }
    dic->str->s = s;
    dic->size++;
    return 0;
}

void dic_free(dictionary* dic)
{
    for (int i = 0; i < dic->size; i++) {
        free(dic->str[i].s);
    }
    free(dic->str);
    free(dic);
}

int fill_dic(dictionary* dic, FILE* in)
{
    char* c = calloc(1, sizeof(char));
    char* s = calloc(1, sizeof(char));
    int id = 0, i = 0;
    while (fread(c, sizeof(char), 1, in) != 0) {
        if (*c != ' ') {
            s[id] = *c;
            id++;
            s = realloc(s, (id + 1) * sizeof(char));
        } else if (id != 0) {
            s[id] = 0;
            id = 0;
            printf("%s", s);
            dic->str[i].s = s;
            i++;
            s = calloc(1, sizeof(char));
        }
    }
    if (id != 0) {
        dic->str[i].s = s;
        s[id] = 0;
    }
}

int nstrcmp(char* str1, char* str2)
{
    if (&str1 == NULL || &str2 == NULL) {
        return -1;
    }
    for (int i = 0; str1 != '\0' || str2 != '\0'; i++) {
        if (str1[i] != str2[i]) {
            if (str1[i] > str2[i]) {
                return 1;
            }
            if (str1[i] < str2[i]) {
                return 2;
            }
        }
    }
    return 0;
}

void swap(char* str1, char* str2)
{
    char tmp;
    tmp = *str1;
    *str1 = *str2;
    *str2 = tmp;
}

void Bubble_Sort(dictionary* dic)
{
    int f;
    for (int i = 0; i < dic->size; i++) {
        for (f = 0; f < dic->size - 1; f++) {
            if (nstrcmp(dic->str[f].s, dic->str[f + 1].s) == 1) {
                swap(&dic->str[f].s, &dic->str[f + 1].s);
            }
        }
    }
}

void int_or_char(char* str)
{
    if (str == NULL) {
        return 0;
    }
    int f = 0;
    for (int i = 0; str != '\0'; i++) {
        if (str[i] > '9' || str[i] < '0') {
            return -1;
        }
        f = f * 10 + str[i] - '0';
    }
    return f;
}
