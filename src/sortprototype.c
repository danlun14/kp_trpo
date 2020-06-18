#include <stdio.h>

int nstrcmp(const char* str1, const char* str2)
{
    if (&str1 == NULL || &str2 == NULL) {
        return -1;
    }
    for (int i = 0; str1 != '\0' || str2 != '\0'; i++) {
        if (str1[i] != str2[i]) {
            if (str1[i] > str2[i]) {
                return 1;
            }
            if (str1[i] < str2[i]) {
                return 2;
            }
        }
    }
    return 0;
}

void swap(char* str1, char* str2)
{
    char tmp;
    tmp = *str1;
    *str1 = *str2;
    *str2 = tmp;
}

void Bubble_Sort(const char* mass_str[], int size)
{
    int g = size;
    int f = 0;
    for (int i = 0; i < g; i++) {
        while (f < g - 1) {
            if (nstrcmp(mass_str[f], mass_str[f + 1]) == 1) {
                swap(&mass_str[f], &mass_str[f + 1]);
                f++;
            }
            f++;
        }
        f = 0;
    }
}

int main()
{
    char abc[] = {'m', 'b', 'c', 'd'};
    char anb[] = {'f', 'b', 'v'};
    char abs[] = {'q', 'b', 'c', 'd'};
    char asndh[] = {'c', 'f', 'v'};
    char* word1 = &abc;
    char* word2 = &anb;
    char* word3 = &abs;
    char* word4 = &asndh;
    char* words[] = {word1, word2, word3, word4};
    Bubble_Sort(words, 4);
    // if (nstrcmp(word1, word2) == -1) {
    //      return -1;
    //  }
    //  return 0;
}