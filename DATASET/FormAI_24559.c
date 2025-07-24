//FormAI DATASET v1.0 Category: Word Count Tool ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void countWords(char* input) {
    int count = 0;
    int i;

    // Removing leading and trailing whitespaces
    char* start = input;
    while (isspace(*start)) start++;
    char* end = input + strlen(input) - 1;
    while (end > start && isspace(*end)) end--;
    *(end + 1) = '\0';

    // Counting words
    for (i = 0; i < strlen(input); i++) {
        if (isspace(input[i])) {
            count++;
            while (isspace(input[i + 1]) && i < strlen(input)) i++;
        }
    }

    count++;
    printf("The number of words in the input is: %d\n", count);
}

int main() {
    char input[1000];
    printf("Enter a sentence: ");
    fgets(input, 1000, stdin);
    countWords(input);

    return 0;
}