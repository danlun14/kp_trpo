#include "command.h"
#include <stdio.h>
#include <string.h>
#define ER1 printf("Usage:\n sort <in-file-name> <out-file-name> [sort-key]\n");

int main(int argc, char* argv[])
{
    if (argc > 4) {
        ER1;
        return -1;
    }
    if (!strcmp(argv[3], "-l")) {
        if (sort_file(argv[1], argv[2], 1)) {
            printf("Error sort from high to low\n");
            return -1;
        }
    } else if ((!strcmp(argv[3], "-u"))) {
        if (sort_file(argv[1], argv[2], -1)) {
            printf("Error sort from low to high\n");
            return -1;
        }
    } else {
        ER1;
    }
    return 0;
}