//FormAI DATASET v1.0 Category: Word Count Tool ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void countWords(char *text) {
    int wordCount = 0;
    int letterCount = 0;
    int i;

    for (i = 0; text[i] != '\0'; i++) {
        if (isspace(text[i])) { // space, tab or newline
            if (letterCount > 0) {
                wordCount++;
                letterCount = 0;
            }
        } else {
            letterCount++;
        }
    }

    if (letterCount > 0) {
        wordCount++;
    }

    printf("Word count: %d\n", wordCount);
}

int main() {
    char text[1000];

    printf("Enter some text:\n");
    fgets(text, 1000, stdin);

    countWords(text);

    return 0;
}