//FormAI DATASET v1.0 Category: Word Count Tool ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_WORD_LENGTH 50

int main() {
    char input[500];
    char *wordList[1000];
    int wordCount[MAX_WORD_LENGTH+1] = { 0 };
    int totalWords = 0;

    printf("Welcome to the C Word Count Tool!\n");
    printf("Please enter your text (max 500 characters):\n");
    fgets(input, 500, stdin);

    char *token = strtok(input, " ");
    while (token != NULL && totalWords < 1000) {
        // Remove any non-alphanumeric characters from the beginning of the word
        while (!isalpha(token[0]) && !isdigit(token[0]) && token[0] != '\0') {
            token++;
        }

        // Remove any non-alphanumeric characters from the end of the word
        int len = strlen(token);
        while (!isalpha(token[len-1]) && !isdigit(token[len-1]) && len > 0) {
            token[len-1] = '\0';
            len--;
        }

        // Check if the word is valid before adding it to the list
        if (strlen(token) >= 1 && strlen(token) <= MAX_WORD_LENGTH) {
            // Convert the word to lowercase for case-insensitive counting
            for (int i = 0; i < strlen(token); i++) {
                token[i] = tolower(token[i]);
            }

            // Check if the word already exists in the list
            int isNewWord = 1;
            for (int i = 0; i < totalWords; i++) {
                if (strcmp(wordList[i], token) == 0) {
                    isNewWord = 0;
                    wordCount[strlen(token)]++;
                    break;
                }
            }

            // If the word is new, add it to the list
            if (isNewWord) {
                wordList[totalWords] = token;
                wordCount[strlen(token)]++;
                totalWords++;
            }
        }

        // Get the next word in the string
        token = strtok(NULL, " ");
    }

    printf("\nWord count by length:\n");
    for (int i = 1; i <= MAX_WORD_LENGTH; i++) {
        printf("%d-letter words: %d\n", i, wordCount[i]);
    }

    return 0;
}