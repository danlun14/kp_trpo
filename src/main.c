#include <stdio.h>
#define ER1 printf("incorrect input file");

int main(int argc, char** argv)
{
    FILE *what, where;
    what = fopen(argv[1], "r");
}