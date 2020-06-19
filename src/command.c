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
        printf("Wrong output file name\n");
        fclose(out);
        fclose(in);
        return -1;
    }
    out = fopen(output_file, "w");
    if (out == NULL) {
        fclose(in);
        return -1;
    }

    dictionary dic;
    dic_init(&dic, 65655);
    printf("%d\n", dic.size);
    fill_dic(&dic, in);
    // printf("%s", dic.str[0].s);
    // printf("%s\n", dic.str[3].s);
    printf("%d\n", dic.size);
    printf("%d\n", dic.capacity);
    sort_dic(&dic);
    printf("%s", dic.str[0].s);
    printf("%s\n", dic.str[3].s);
    return 0;
}
