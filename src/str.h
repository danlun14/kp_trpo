#include <stdio.h>
#include <stdlib.h>

typedef struct {
} Sep_sym;

typedef struct {
    char* s;
} word;

typedef struct {
    word* str;
    long int* nums;
    int size_s;
    int size_n;
    int capacity;
} dictionary;

int dic_init();

int write_in_dic(dictionary* dic, char* s1);

void dic_free(dictionary* dic);

int fill_dic(dictionary* dic, FILE* in);

int scmp(char* str1, char* str2);

void swap_pointers(char** str1, char** str2);

void sort_str(dictionary* dic);

void dic_out(FILE* out, dictionary* dic);

long int is_digit(char* str);

int symbol_check(char* s);

void int_Bubble_sort(dictionary* dic);