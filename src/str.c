#include "str.h"

int symbol_check(char* s)
{
    if (*s == ' ') {
        return 1;
    }
    if (*s == '.') {
        return 1;
    }
    if (*s == '\n') {
        return 1;
    }
    if (*s == '/') {
        return 1;
    }
    if (*s == '_') {
        return 1;
    }
    if (*s == '-') {
        return 1;
    }
    if (*s == '+') {
        return 1;
    }
    if (*s == '=') {
        return 1;
    }
    if (*s == ',') {
        return 1;
    }
    if (*s == '?') {
        return 1;
    }
    if (*s == '!') {
        return 1;
    }
    return 0;
}

int scmp(char* s1, char* s2)
{
    if (&s1 == NULL || &s2 == NULL) {
        return -1;
    }
    for (int i = 0; s1[i] != '\0' || s2[i] != '\0'; i++) {
        if (s1[i] != s2[i]) {
            if (s1[i] > s2[i]) {
                return 1;
            } else if ((s1[i] < s2[i])) {
                return 2;
            }
        }
    }
    return 0;
}

int slen(char* s)
{
    if (s == NULL) {
        return -1;
    }
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

long int is_digit(char* s)
{
    if (s == NULL) {
        return -2;
    }
    char* endPtr;
    int len = slen(s);
    long int num = strtol(s, &endPtr, 10);
    if ((endPtr - s) == len && num < 2147483647) {
        return num;
    }
    return -1;
}

/*************************SWAP*************************/

void swap_int(long int* num1, long int* num2)
{
    long int tmp;
    tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}

void swap_pointers(char** s1, char** s2)
{
    char* tmp;
    tmp = *s1;
    *s1 = *s2;
    *s2 = tmp;
}