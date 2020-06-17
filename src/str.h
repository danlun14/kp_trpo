#include <stdio.h>

typedef struct {
    char* s;
} string;

typedef struct {
    string* word;
    int size;
    int capacity;
} dictionary;

dictionary* dic_init();

int write_in_dic(dictionary* dic, char* s1);

void dic_free(dictionary* dic);