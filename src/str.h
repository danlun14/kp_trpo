#include <stdio.h>

typedef struct {
    char* s;
} string;

typedef struct {
    string* word;
    int size;
    int capacity;
} dictionary;
