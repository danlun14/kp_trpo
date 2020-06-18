#include "str.h"
#include <stdio.h>
#include <string.h>

dictionary* dic_init()
{
    dictionary* dic = calloc(1, sizeof(dictionary));
    dic->str = calloc(65565, sizeof(word));
    if (dic->str == NULL) {
        return NULL;
    }
    dic->size = 0;
    dic->capacity = 1;
    return dic;
}

int write_in_dic(dictionary* dic, char* s)
{
    dic->str->s = s;
    dic->size++;
    return 1;
}

void dic_free(dictionary* dic)
{
    for (int i = 0; i < dic->size; i++) {
        free(dic->str[i].s);
    }

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
    }
}
