#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

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
void dic_free(dictionary* dic);

int str_to_dic(dictionary* dic, char* s);
int num_to_dic(dictionary* dic, int num);
int fill_dic(dictionary* dic, FILE* in);

void sort_int(dictionary* dic);
void sort_str(dictionary* dic);

void dic_out_u(FILE* out, dictionary* dic);
void dic_out_l(FILE* out, dictionary* dic);

#endif