//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 50  // maximum number of words to count
#define MAX_LENGTH 50 // maximum length of a word

int main() {
    char text[MAX_WORDS][MAX_LENGTH]; // array to store words
    int count[MAX_WORDS] = {0};       // array to store word count
    char input[1000];                 // input text
    int num_words = 0;                // number of words to count
    int i, j;

    printf("Enter a sentence or phrase: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // remove the newline character

    // extract words from input text and store them in text array
    char *token = strtok(input, " ");
    while (token != NULL && num_words < MAX_WORDS) {
        strcpy(text[num_words], token);
        num_words++;
        token = strtok(NULL, " ");
    }

    // count word frequency
    for (i = 0; i < num_words; i++) {
        if (!isalpha(text[i][0])) {
            continue; // skip non-alphabetic words
        }
        for (j = i + 1; j < num_words; j++) {
            if (strcmp(text[i], text[j]) == 0) {
                count[i]++;
            }
        }
    }

    // print the word frequency
    printf("\nWord frequency:\n");
    for (i = 0; i < num_words; i++) {
        if (count[i] == 0) {
            continue; // skip non-repeating words
        }
        printf("\"%s\" occurs %d times\n", text[i], count[i] + 1);
    }

    return 0;
}