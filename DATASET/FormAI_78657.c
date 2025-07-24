//FormAI DATASET v1.0 Category: Word Count Tool ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to count the number of words in a string */
int wordCount(char *str) {
    int count = 0;
    char *token = strtok(str, " ");

    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }

    return count;
}

int main() {
    char str[1000];

    printf("Enter a string: ");
    fgets(str, 1000, stdin);

    printf("Number of words in the string: %d\n", wordCount(str));

    return 0;
}