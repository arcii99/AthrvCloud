//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: Sherlock Holmes
// Watson, my dear fellow, we have been tasked with a most curious challenge - to create a program that tallies the frequency of unique words in a given text document.
// Fear not, for I have just the solution for this testing conundrum. Observe, my good doctor, the following C program that will accomplish our task with efficiency and grace.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50
#define MAX_WORDS 100000

// Define our word structure that encapsulates the word itself and its respective frequency count.
typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} word_t;

// This compare function will allow us to sort our words in descending order by their frequency count.
int compare(const void *p, const void *q) {
    const word_t *a = p;
    const word_t *b = q;
    return b->count - a->count;
}

int main() 
{
    int i, j, k, count = 0;
    char fileName[MAX_WORD_LEN];
    char word[MAX_WORD_LEN];
    char buffer[MAX_WORD_LEN];
    FILE *file;
    word_t words[MAX_WORDS] = {0};
    printf("Kindly provide the name of the text file: ");
    scanf("%s", fileName);

    // Open the file for reading and handle any potential errors.
    if (!(file = fopen(fileName, "r"))) {
        printf("Could not open file %s\n", fileName);
        exit(1);
    }

    // Read the file word-by-word and increment the frequency count for each unique word.
    while (fscanf(file, "%s", buffer) == 1) {
        // Convert the word to lowercase.
        for (i = 0; buffer[i]; i++) {
            word[i] = tolower(buffer[i]);
        }
        word[i] = '\0';

        // Attempt to find the word in our list of unique words.
        for (j = 0; j < count; j++) {
            if (strcmp(word, words[j].word) == 0) {
                words[j].count++;
                break;
            }
        }
        // If the word isn't already in our list, add it to the end of the list.
        if (j == count) {
            strcpy(words[count].word, word);
            words[count].count = 1;
            count++;
        }
    }

    // Sort the list of unique words by frequency count.
    qsort(words, count, sizeof(word_t), compare);

    // Print out the results of our analysis.
    printf("\nThe most frequent words are:\n");
    for (i = 0; i < count && i < 10; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    // Close the file and exit the program.
    fclose(file);
    return 0;
}