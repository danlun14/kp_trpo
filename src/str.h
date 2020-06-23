#ifndef STR_H
#define STR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int symbol_check(char* s);

int scmp(char* s1, char* s2);
int slen(char* s);
long int is_digit(char* s);

void swap_pointers(char** s1, char** s2);
void swap_int(long int* num1, long int* num2);

#endif