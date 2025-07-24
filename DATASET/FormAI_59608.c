//FormAI DATASET v1.0 Category: Text processing ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the text processing program!\n");

    char text[500];
    printf("\nEnter some text: ");
    fgets(text, 500, stdin);

    int wordCount = 1;
    int charCount = 0;
    int vowelCount = 0;
    int punctuationCount = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        charCount++;

        if (text[i] == ' ') {
            wordCount++;
        }

        if (text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u' || text[i] == 'y' || text[i] == 'A' || text[i] == 'E' || text[i] == 'I' || text[i] == 'O' || text[i] == 'U' || text[i] == 'Y') {
            vowelCount++;
        }

        if (text[i] == '.' || text[i] == ',' || text[i] == '!' || text[i] == '?' || text[i] == ':' || text[i] == ';') {
            punctuationCount++;
        }
    }

    printf("\nThere are %d words in your text.\n", wordCount);
    printf("There are %d characters in your text.\n", charCount);
    printf("There are %d vowels in your text.\n", vowelCount);
    printf("There are %d punctuation marks in your text.\n", punctuationCount);

    return 0;
}