//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 128
#define MAX_NUM_WORDS 10000

typedef struct word_t {
    char str[MAX_WORD_LENGTH];
    int count;
} Word;

int compare_words(const void *a, const void *b) {
    return ((Word *)b)->count - ((Word *)a)->count;
}

int main() {
    Word words[MAX_NUM_WORDS];
    int num_words = 0;

    // read in input from user
    char input[10000];
    printf("Enter text to analyze:\n");
    fgets(input, sizeof(input), stdin);

    // convert input to lowercase
    for (int i = 0; i < strlen(input); i++) {
        input[i] = tolower(input[i]);
    }

    // tokenize words
    char *token = strtok(input, " ,.-\n");
    while (token != NULL && num_words < MAX_NUM_WORDS) {
        int found = 0;
        // check if word already exists in array
        for (int i = 0; i < num_words; i++) {
            if (strcmp(words[i].str, token) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }
        // if word doesn't exist in array, add it
        if (!found) {
            Word new_word;
            strcpy(new_word.str, token);
            new_word.count = 1;
            words[num_words] = new_word;
            num_words++;
        }
        token = strtok(NULL, " ,.-\n");
    }

    // sort words by frequency
    qsort(words, num_words, sizeof(Word), compare_words);

    // print results
    printf("\nWord frequencies:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].str, words[i].count);
    }
    
    return 0;
}