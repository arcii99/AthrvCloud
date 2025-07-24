//FormAI DATASET v1.0 Category: Text processing ; Style: Ada Lovelace
// This program processes a text file and outputs statistics on the file.
// It was inspired by Ada Lovelace's work on the Analytical Engine.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of words in the text file
#define MAX_WORDS 10000

// Define a structure to store words and their frequency counts
typedef struct {
   char word[50];
   int count;
} WordFreq;

int main(int argc, char *argv[]) {
    
    // Check that a filename was provided as a command-line argument
    if (argc < 2) {
        printf("Usage: textproc <filename>\n");
        return 1;
    }

    // Open the input file for reading
    FILE *infile = fopen(argv[1], "r");
    if (infile == NULL) {
        printf("Unable to open file: %s\n", argv[1]);
        return 1;
    }

    // Initialize an array to store words and their frequency counts
    WordFreq *words[MAX_WORDS];
    int num_words = 0;

    // Read each line of the input file
    char line[1000];
    while (fgets(line, sizeof(line), infile)) {
        
        // Tokenize each line into words
        char *word = strtok(line, " ,.;'\"()!?");

        while (word != NULL) {
            // Convert each word to lowercase
            for (int i=0; i<strlen(word); i++) {
                word[i] = tolower(word[i]);
            }

            // Check if the word already exists in the array
            int found = 0;
            for (int i=0; i<num_words; i++) {
                if (strcmp(words[i]->word, word) == 0) {
                    // If the word is found, increment its count
                    words[i]->count++;
                    found = 1;
                    break;
                }
            }

            // If the word was not found, add it to the array
            if (!found && num_words < MAX_WORDS) {
                WordFreq *new_word = malloc(sizeof(WordFreq));
                strcpy(new_word->word, word);
                new_word->count = 1;
                words[num_words] = new_word;
                num_words++;
            }

            word = strtok(NULL, " ,.;'\"()!?");
        }
    }

    // Close the input file
    fclose(infile);

    // Output the statistics for the text file
    printf("Total words processed: %d\n", num_words);

    // Sort the array of words in alphabetical order
    for (int i=0; i<num_words; i++) {
        for (int j=i+1; j<num_words; j++) {
            if (strcmp(words[i]->word, words[j]->word) > 0) {
                WordFreq *temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }

    // Output the frequency count for each word
    printf("\nWord frequency count:\n");
    for (int i=0; i<num_words; i++) {
        printf("%s: %d\n", words[i]->word, words[i]->count);
    }

    // Free the memory used by the array of words
    for (int i=0; i<num_words; i++) {
        free(words[i]);
    }

    return 0;
}