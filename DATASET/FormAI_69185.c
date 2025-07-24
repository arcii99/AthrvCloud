//FormAI DATASET v1.0 Category: Word Count Tool ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[1000];
    int numWords = 0, numChars = 0, numLines = 0, inWord = 0;
    printf("Welcome to the C Word Count Tool!\n");
    printf("Enter your text (up to 1000 characters) and end with CTRL+D:\n");
    while (fgets(input, 1000, stdin) != NULL) {
        numChars += strlen(input);
        for (int i = 0; i < strlen(input); i++) {
            if (input[i] == '\n') {
                numLines++;
            }
            if (isalpha(input[i])) {
                if (!inWord) {
                    inWord = 1;
                    numWords++;
                }
            } else {
                inWord = 0;
            }
        }
    }
    printf("Number of words in the text: %d\n", numWords);
    printf("Number of characters in the text: %d\n", numChars);
    printf("Number of lines in the text: %d\n", numLines);
    printf("Thank you for using the C Word Count Tool!");
    return 0;
}