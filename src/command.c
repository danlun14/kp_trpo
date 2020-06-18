#include "str.h"
#include <stdio.h>

int sort_file(const char* input_file, const char* output_file, int sort_type)
{
    FILE* in = fopen(input_file, "r");
    if (in == NULL) {
        return -1;
    }
    FILE* out = fopen(output_file, "r");
    if (out != NULL) {
        printf("Wrong output file name");
        fclose(out);
        fclose(in);
        return -1;
    }
    out = fopen(output_file, "w");
    if (out == NULL) {
        fclose(in);
        return -1;
    }

    dictionary* dic;
    dic = dic_init();

    fill_dic(dic, in);
    printf("%s", dic->str[2].s);
    return 0;
}
