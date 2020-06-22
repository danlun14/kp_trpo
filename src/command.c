#include "sort.h"
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
    // printf("%d\n", dic.size_s);
    fill_dic(&dic, in);

    sort_str(&dic);
    printf("%d\n", dic.size_s);
    sort_int(&dic);
    if (sort_type > 0) {
        // printf("%d\n", dic.nums[8]);
        dic_out_u(out, &dic);
    }
    if (sort_type < 0) {
        // printf("%d\n", dic.nums[8]);
        dic_out_l(out, &dic);
    }
    dic_free(&dic);
    return 0;
}
