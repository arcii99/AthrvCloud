//FormAI DATASET v1.0 Category: Word Count Tool ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countWords(char *inputString);

int main() {
    char input[1000];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    printf("Word count: %d", countWords(input));
    return 0;
}

int countWords(char *inputString) {
    int count = 0;
    int i, n;
    n = strlen(inputString);

    for (i = 0; i < n; i++) {
        // Check if current character is a space, tab, or newline
        if (inputString[i] == ' ' || inputString[i] == '\t' || inputString[i] == '\n') {
            count++;
        }
    }

    // Add 1 for the last word
    count++;

    return count;
}