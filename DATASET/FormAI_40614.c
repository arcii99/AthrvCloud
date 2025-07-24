//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define a struct to hold the word and its count
typedef struct {
    char *word;
    int count;
} WordCount;

// Function to create a new WordCount struct
WordCount* createWordCount(char *word) {
    WordCount *wc = malloc(sizeof(WordCount));
    wc->word = word;
    wc->count = 1;
    return wc;
}

int main() {
    // Define the input file and frequency table
    char *filename = "input.txt";
    WordCount *freqTable[1000];
    int numWords = 0;

    // Open and read the input file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening %s. Exiting.\n", filename);
        exit(1);
    }
    char line[100];
    while (fgets(line, 100, file) != NULL) {
        // Split the line into words
        char *word = strtok(line, " \n");
        while (word != NULL) {
            // Convert the word to lowercase
            for (int i = 0; i < strlen(word); i++) {
                word[i] = tolower(word[i]);
            }
            // Check if the word is already in freqTable
            int found = 0;
            for (int i = 0; i < numWords; i++) {
                if (strcmp(word, freqTable[i]->word) == 0) {
                    freqTable[i]->count++;
                    found = 1;
                    break;
                }
            }
            // If the word is not in freqTable, add it
            if (!found) {
                freqTable[numWords] = createWordCount(word);
                numWords++;
            }
            // Get the next word
            word = strtok(NULL, " \n");
        }
    }
    fclose(file);

    // Print the frequency table
    printf("Word Frequency Count:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", freqTable[i]->word, freqTable[i]->count);
    }

    // Free the memory used by freqTable
    for (int i = 0; i < numWords; i++) {
        free(freqTable[i]->word);
        free(freqTable[i]);
    }

    return 0;
}