//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: genious
#include <stdio.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20

int main() {
    char word[MAX_WORD_LENGTH];
    int frequency[MAX_WORD_LENGTH] = {0};
    int sum = 0;

    printf("Enter a sentence: ");

    while (scanf("%s", word) == 1) {
        int word_length = 0;

        for (int i = 0; word[i] != '\0'; i++) {
            if (isalpha(word[i])) {
                word[word_length++] = tolower(word[i]);
            }
        }
        word[word_length] = '\0';

        if (word_length > 0) {
            frequency[word_length]++;
            sum++;
        }
    }

    printf("\nLength\tFrequency\n");
    printf("-----------------\n");

    for (int i = 1; i < MAX_WORD_LENGTH; i++) {
        if (frequency[i] > 0) {
            printf("%-6d\t%d\n", i, frequency[i]);
        }
    }

    printf("\nTotal number of words: %d\n", sum);

    return 0;
}