//FormAI DATASET v1.0 Category: Word Count Tool ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 1000

void countWords(char[], int*);

int main()
{
    char str[MAX_SIZE];
    int count = 0;

    printf("Enter a string: ");
    fgets(str, MAX_SIZE, stdin);

    countWords(str, &count);

    printf("Total number of words = %d\n", count);

    return 0;
}

void countWords(char str[], int* count)
{
    int length = strlen(str);
    bool word = false;

    for (int i = 0; i < length; i++) {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            word = false;
        } else if (!word) {
            (*count)++;
            word = true;
        }
    }
}