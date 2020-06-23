#ifndef COMMAND_H
#define COMMAND_H

#include <stdio.h>

int sort_file(const char* input_file, const char* output_file, int sort_type);

int open_files(
        const char* input_file, const char* output_file, FILE** in, FILE** out);

#endif