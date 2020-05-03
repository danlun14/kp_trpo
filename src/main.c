#include <stdio.h>
#define ER1 printf("incorrect input file");

int main(int argc, char** argv)
{
    FILE *what, *where;
    int typeofsort = 0;
    int key;

    what = fopen(argv[1], "r");
    if (what == NULL) {
        ER1;
        return -1;
    }
    where = fopen(argv[2], "r");
    if (where != NULL) {
        char f;
        printf("Are you want to rewrite file?(y/n)");

        while (key != 0) {
            scanf("%s", &f);
            if (f == "y") {
                key = 0;
            } else if (f == "n") {
                return 0;
            } else if (key != 0) {
                printf("Wrong symbol");
            }
        }
    }
    if (argv[2] == '-u') {
        typeofsort = 1;
    } else if (argv[2] == '-l') {
        typeofsort = -1;
    } else if (typeofsort != 1 || typeofsort != -1) {
        ER1;
        return -1;
    }
    if (typeofsort == 1) {
    } else if (typeofsort == -1) {
    }

    return 1;
}