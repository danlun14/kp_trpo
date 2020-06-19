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
            dic->size++;
            // printf("%s", s);
            dic->str[i].s = s;
            i++;
            s = calloc(1, sizeof(char));
        }
    }
    if (id != 0) {
        dic->size++;
        dic->str[i].s = s;
        s[id] = 0;
    }
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
            }
            if (str1[i] < str2[i]) {
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

void sort_dic(dictionary* dic)
{
    int f;
    for (int i = 0; i < dic->size; i++) {
        for (f = 0; f < dic->size - 1; f++) {
            if (scmp(dic->str[f].s, dic->str[f + 1].s) == 1) {
                swap_pointers(&dic->str[f].s, &dic->str[f + 1].s);
            }
        }
    }
}

int dic_out(FILE* out, dictionary* dic)
{
    for (int i = 0; i < dic->size; i++) {
        fprintf(out, "%s\n", dic->str[i].s);
    }
}