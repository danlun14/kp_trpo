#include <stdio.h>

int lower_sort_from_file(const char* input_file, const char* output_file)
{
    FILE* in = fopen(input_file, "r");
    if (in == NULL) {
        return -1;
    }
}

int upper_sort_from_file(const char* input_file, const char* output_file)
{
    FILE* in = fopen(input_file, "r");
    if (in == NULL) {
        return -1;
    }
}