#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char* s;
} word;

typedef struct {
    word* str;
    int size;
    int capacity;
} dictionary;

void dic_init();

int write_in_dic(dictionary* dic, char* s1);

void dic_free(dictionary* dic);

int fill_dic(dictionary* dic, FILE* in);

int scmp(char* str1, char* str2);

void swap_pointers(char** str1, char** str2);

void sort_dic(dictionary* dic);