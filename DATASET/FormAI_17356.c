//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: irregular
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 5000

// A play on words!
struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

typedef struct word_count WordCount;

// Here we go!
int main() {
    WordCount words[MAX_WORDS];
    char input[MAX_WORD_LENGTH];
    int num_words = 0;

    // This counts the number of words
    while (scanf("%49s", input) == 1) {

        // Convert all charactes to lowercase
        for (int i = 0; i < strlen(input); i++) {
            input[i] = tolower(input[i]);
        }

        // We are making a new struction for every word!
        int found = 0;
        for (int i = 0; i < num_words; i++) {
            if (strcmp(input, words[i].word) == 0) {
                words[i].count++; // if found then increment the count
                found = 1;
                break;
            }
        }

        // If the word doesn't exist, add it to the list
        if (!found) {
            strcpy(words[num_words].word, input);
            words[num_words].count = 1;
            num_words++;
        }
    }

    // Print the results
    printf("Word Frequency Counter:\n");
    printf("=======================\n");

    for (int i = 0; i < num_words; i++) {

        // A punny way to show the frequency of a word!
        printf("%s occurs %d time%s.\n", words[i].word, words[i].count, words[i].count > 1 ? "s" : "");
    }

    return 0; // done!
}