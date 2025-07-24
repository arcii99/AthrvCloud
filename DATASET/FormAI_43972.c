//FormAI DATASET v1.0 Category: Text processing ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[1000], *word, delim[] = " ,.?!";
    int count = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    word = strtok(str, delim);
    while (word != NULL) {
        count++;
        printf("%d. %s\n", count, word);
        word = strtok(NULL, delim);
    }

    printf("Total number of words: %d\n", count);

    return 0;
}