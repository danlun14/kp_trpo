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
