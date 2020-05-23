#include <stdio.h>

int lower_sort_from_file(const char* input_file, const char* output_file)
{
    FILE* in = fopen(input_file, "r");
    if (in == NULL) {
        return -1;
    }
    FILE* out = fopen(output_file, "r");
    if (out != NULL) {
        printf("Wrong output file name");
        fclose(out);
    }
    FILE* out = fopen(output_file, "w");
    if (out == NULL) {
        fclose(in);
        return -1;
    }
}

int upper_sort_from_file(const char* input_file, const char* output_file)
{
    FILE* in = fopen(input_file, "r");
    if (in == NULL) {
        return -1;
    }
    FILE* out = fopen(output_file, "r");
    if (out != NULL) {
        printf("Wrong output file name");
        fclose(out);
    }
    FILE* out = fopen(output_file, "w");
    if (out == NULL) {
        fclose(in);
        return -1;
    }
}