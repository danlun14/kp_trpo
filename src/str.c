#include "str.h"
#include <stdio.h>

dictionary* dic_init()
{
    dictionary* dic = malloc(1 * sizeof(dictionary));
    dic->size = 0;
    dic->capacity = 0;
    return dic;
}

int write_in_dic(dictionary* dic, char* s1)
{
    if (dic->capacity == dic->size) {
        dic->capacity *= 2;
        dic->word = realloc((dic->capacity + 1) * sizeof(string));
    }
    dic->word[dic->size].s = s1;
    dic->size++;
    return 1;
}

void dic_free(dictionary* dic)
{
    for (int i = 0; i < dic->size; i++) {
        free(dic->word[i].s);
    }
    free(dic->word);
    free(dic);
}