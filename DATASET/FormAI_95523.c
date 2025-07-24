//FormAI DATASET v1.0 Category: Word Count Tool ; Style: creative
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
    int words = 0, lines = 0, characters = 0;

    printf("Enter a sentence: ");

    while (1) { // Infinite Loop
        int c = getchar();

        if (c == EOF || c == '\n') {
            lines++;
        }

        if (isalnum(c)) {
            characters++;
        }

        if (isspace(c)) {
            words++;
        }

        if (c == EOF) {
            break; // Break the Infinite Loop
        }
    }

    printf("\n");
    printf("Word count: %d\n", words);
    printf("Line count: %d\n", lines);
    printf("Character count: %d\n", characters);

    return 0;
}