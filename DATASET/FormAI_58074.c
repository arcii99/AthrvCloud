//FormAI DATASET v1.0 Category: Word Count Tool ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wordCount(char *text) {
    int count = 0;
    char *word;

    word = strtok(text, " ");

    while (word != NULL) {
        count++;
        word = strtok(NULL, " ");
    }

    return count;
}

int main() {
    char text[1000];

    printf("Enter the text: ");
    fgets(text, 1000, stdin);

    // Removing the newline character
    text[strcspn(text, "\n")] = 0;

    printf("The word count of the text is: %d\n", wordCount(text));

    return 0;
}