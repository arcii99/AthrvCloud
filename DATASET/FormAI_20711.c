//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: complete
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 40
#define MAX_WORDS 5000

int main() {
    char word[MAX_WORD_LENGTH];
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int frequencies[MAX_WORDS];
    int num_words = 0;

    // read input from user
    printf("Enter a string: ");
    fgets(word, MAX_WORD_LENGTH, stdin);
    
    // remove newline character from input
    word[strcspn(word, "\n")] = '\0';

    // convert input to lowercase
    for (int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }

    // parse input into individual words
    char *p = strtok(word, " ");
    while (p != NULL) {
        strcpy(words[num_words], p);
        frequencies[num_words] = 1;
        num_words++;
        p = strtok(NULL, " ");
    }

    // count word frequencies
    for (int i = 0; i < num_words; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                frequencies[i]++;
                frequencies[j] = 0;
            }
        }
    }

    // print word frequencies
    printf("Word frequencies:\n");
    for (int i = 0; i < num_words; i++) {
        if (frequencies[i] != 0) {
            printf("%s: %d\n", words[i], frequencies[i]);
        }
    }

    return 0;
}