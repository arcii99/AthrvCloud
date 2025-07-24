//FormAI DATASET v1.0 Category: Text Summarizer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// function to calculate the frequency of each word
void calculateFrequency(char *text, int word_count, char **words, int *frequencies) {
    // loop through each word and add the frequency to the array
    for (int i = 0; i < word_count; i++) {
        frequencies[i] = 1; // initialize frequency to 1
        for (int j = i + 1; j < word_count; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                frequencies[i]++;
                for (int k = j; k < word_count - 1; k++) {
                    strcpy(words[k], words[k + 1]);
                }
                word_count--;
                j--;
            }
        }
    }
}

// function to print the top n words with their frequencies
void printTopWords(int n, char **words, int *frequencies, int count) {
    // sort the words based on their frequencies
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (frequencies[j] > frequencies[i]) {
                int temp = frequencies[j];
                frequencies[j] = frequencies[i];
                frequencies[i] = temp;

                char *temp_word = words[j];
                words[j] = words[i];
                words[i] = temp_word;
            }
        }
    }

    // print the top n words and their frequencies
    for (int i = 0; i < n && i < count; i++) {
        printf("%s : %d\n", words[i], frequencies[i]);
    }
}

// function to remove punctuation from a string
void removePunctuation(char *text) {
    for (int i = 0; i < strlen(text); i++) {
        if (ispunct(text[i])) {
            for (int j = i; j < strlen(text) - 1; j++) {
                text[j] = text[j + 1];
            }
            text[strlen(text) - 1] = '\0';
            i--;
        }
    }
}

int main() {
    char text[10000];
    char *words[1000];
    int frequencies[1000];
    int word_count = 0;

    printf("Enter text to summarize: ");
    fgets(text, 10000, stdin);
    removePunctuation(text);

    // split the text into words
    char *word = strtok(text, " ");
    while (word != NULL) {
        words[word_count++] = word;
        word = strtok(NULL, " ");
    }

    // calculate the frequency of each word
    calculateFrequency(text, word_count, words, frequencies);

    // print the top 10 words and their frequencies
    printf("\nTop 10 Words:\n");
    printTopWords(10, words, frequencies, word_count);

    return 0;
}