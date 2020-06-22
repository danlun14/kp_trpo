#include "sort.h"
#include "str.h"

int dic_init(dictionary* dic, int capacity)
{
    dic->str = calloc(capacity, sizeof(word));
    if (dic->str == NULL) {
        return -1;
    }
    dic->nums = calloc(capacity, sizeof(long int));
    if (dic->nums == NULL) {
        free(dic->str);
        return -1;
    }
    dic->size_s = 0;
    dic->size_n = 0;
    dic->capacity = capacity;
}

void dic_free(dictionary* dic)
{
    for (int i = 0; i < dic->size_s; i++) {
        free(dic->str[i].s);
    }
    free(dic->nums);
    free(dic->str);
}

/*************************WRITE_IN_DIC**************************/

int str_to_dic(dictionary* dic, char* s)
{
    if (dic->size_s == dic->capacity) {
        return -1;
    }
    dic->str[dic->size_s].s = s;
    dic->size_s++;
    return 0;
}

int num_to_dic(dictionary* dic, int num)
{
    if (dic->size_n == dic->capacity) {
        return -1;
    }
    dic->nums[dic->size_n] = num;
    dic->size_n++;
    return 0;
}

int fill_dic(dictionary* dic, FILE* in)
{
    char* c = calloc(1, sizeof(char));
    char* s = calloc(1, sizeof(char));
    int id = 0, check;
    while (fread(c, sizeof(char), 1, in) != 0) {
        check = symbol_check(c);
        printf("%d", check);
        if (check == 0) {
            s[id] = *c;
            id++;
            s = realloc(s, (id + 1) * sizeof(char));
        } else if (id != 0) {
            s[id] = 0;
            id = is_digit(s);
            if (id > 0) {
                num_to_dic(dic, id);
            } else {
                str_to_dic(dic, s);
            }
            id = 0;
            // printf("%s", s);
            s = calloc(1, sizeof(char));
        }
    }
    if (id != 0) {
        id = is_digit(s);
        if (id > 0) {
            num_to_dic(dic, id);
        } else {
            str_to_dic(dic, s);
        }
        s[id] = 0;
    }
    return 0;
}

/*************************DIC_OUT**************************/

void dic_out_u(FILE* out, dictionary* dic)
{
    for (int i = 0; i < dic->size_n; i++) {
        fprintf(out, "%li\n", dic->nums[i]);
    }
    for (int i = 0; i < dic->size_s; i++) {
        fprintf(out, "%s\n", dic->str[i].s);
    }
}

void dic_out_l(FILE* out, dictionary* dic)
{
    for (int i = dic->size_s - 1; i > -1; i--) {
        fprintf(out, "%s\n", dic->str[i].s);
    }
    for (int i = dic->size_n - 1; i > -1; i--) {
        fprintf(out, "%li\n", dic->nums[i]);
    }
}

/*************************SORT*****************************/

void sort_str(dictionary* dic)
{
    for (int i = 0; i < dic->size_s; i++) {
        for (int j = 0; j < dic->size_s - 1; j++) {
            if (scmp(dic->str[j].s, dic->str[j + 1].s) == 1) {
                swap_pointers(&dic->str[j].s, &dic->str[j + 1].s);
            }
        }
    }
}

void sort_int(dictionary* dic)
{
    for (int i = 0; i < dic->size_n; i++) {
        for (int j = 0; j < dic->size_n - 1; j++) {
            if (dic->nums[j] > dic->nums[j + 1]) {
                swap_int(dic->nums + j, dic->nums + j + 1);
            }
        }
    }
}
