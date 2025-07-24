//FormAI DATASET v1.0 Category: Word Count Tool ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000  // maximum number of words to be counted
#define MAX_WORD_LEN 50 // maximum length of a word

// function to convert all characters in a string to lowercase
void toLower(char *str) {
    int i = 0;
    while (str[i]) {
        str[i] = tolower(str[i]);
        i++;
    }
}

// function to insert a word into the word count array
void insertWord(char **words, int *counts, int *num_words, char *word) {
    int i;
    for (i = 0; i < *num_words; i++) {
        if (strcmp(words[i], word) == 0) { // word already exists
            counts[i]++;
            return;
        }
    }
    // word does not exist, add it to the array
    words[*num_words] = (char*) malloc((strlen(word) + 1) * sizeof(char));
    strcpy(words[*num_words], word);
    counts[*num_words] = 1;
    (*num_words)++;
}

// function to print the word count array in descending order of frequency
void printWordCount(char **words, int *counts, int num_words) {
    int i, j;
    for (i = 0; i < num_words-1; i++) {
        for (j = i+1; j < num_words; j++) {
            if (counts[j] > counts[i]) { // swap elements if necessary
                int temp_count = counts[i];
                char *temp_word = words[i];
                counts[i] = counts[j];
                words[i] = words[j];
                counts[j] = temp_count;
                words[j] = temp_word;
            }
        }
    }
    printf("\nWord Count Results:\n");
    for (i = 0; i < num_words; i++) {
        printf("%s : %d\n", words[i], counts[i]);
    }
}

int main() {
    char **words = (char**) malloc(MAX_WORDS * sizeof(char*)); // array to store words
    int *counts = (int*) calloc(MAX_WORDS, sizeof(int)); // array to store word frequencies
    int num_words = 0;
    char str[MAX_WORD_LEN];
    printf("Welcome to the C Word Count Tool Multiplayer Style!\n");
    printf("Player 1 please enter your sentence: ");
    fgets(str, MAX_WORD_LEN, stdin);
    strtok(str, "\n"); // remove the trailing newline
    toLower(str); // convert all characters to lowercase
    char *word = strtok(str, " "); // get the first word
    while (word) {
        insertWord(words, counts, &num_words, word);
        word = strtok(NULL, " "); // get the next word
        if (num_words == MAX_WORDS) { // array is full, cannot add more words
            printf("Maximum number of words reached.\n");
            break;
        }
    }
    printf("\nPlayer 2 please enter your sentence: ");
    fgets(str, MAX_WORD_LEN, stdin);
    strtok(str, "\n"); // remove the trailing newline
    toLower(str); // convert all characters to lowercase
    word = strtok(str, " "); // get the first word
    while (word) {
        insertWord(words, counts, &num_words, word);
        word = strtok(NULL, " "); // get the next word
        if (num_words == MAX_WORDS) { // array is full, cannot add more words
            printf("Maximum number of words reached.\n");
            break;
        }
    }
    printWordCount(words, counts, num_words);
    // free memory allocated for words and counts arrays
    for (int i = 0; i < num_words; i++) {
        free(words[i]);
    }
    free(words);
    free(counts);
    return 0;
}