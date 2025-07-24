//FormAI DATASET v1.0 Category: Word Count Tool ; Style: lively
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void countWords(char *string) {
    int numWords = 0;
    char *word = strtok(string, " ");
    while (word != NULL) {
        numWords++;
        word = strtok(NULL, " ");
    }
    printf("Number of words: %d\n", numWords);
}

void countCharacters(char *string) {
    int numChars = 0;
    for (int i = 0; i < strlen(string); i++) {
        char c = string[i];
        if (isalpha(c)) {
            numChars++;
        }
    }
    printf("Number of characters: %d\n", numChars);
}

int main() {
    printf("Welcome to the C Word Count Tool!\n");
    printf("Please enter the text to be evaluated:\n");
    char input[1000];
    fgets(input, 1000, stdin);
    printf("You entered:\n%s", input);
    countWords(input);
    countCharacters(input);
    return 0;
}