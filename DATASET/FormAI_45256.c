//FormAI DATASET v1.0 Category: Word Count Tool ; Style: happy
#include <stdio.h>
#include <ctype.h>

int main() {
    printf("Welcome to the C Word Count Tool!\n");
    printf("Enter your text below (press Ctrl+D when finished):\n");

    int wordCount = 0;
    int charCount = 0;
    int isNewWord = 1;
    char currentChar = getchar();

    while (currentChar != EOF) {
        if (!isspace(currentChar)) {
            charCount++;
            if (isNewWord) {
                wordCount++;
                isNewWord = 0;
            }
        } else {
            isNewWord = 1;
        }
        currentChar = getchar();
    }

    printf("\nYour text has %d words and %d characters!\n", wordCount, charCount);

    printf("Thanks for using the C Word Count Tool, have a wonderful day!");

    return 0;
}