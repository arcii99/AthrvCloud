//FormAI DATASET v1.0 Category: Word Count Tool ; Style: visionary
// This program is a visionary C Word Count Tool that can count the number of words in a given text file.
// It enhances the traditional word count by adding some unique features such as case-insensitivity and the ability to
// remove stop words.
// The program first reads the text file and stores its content in a buffer.
// Then, it removes punctuation marks, if any, and converts all the characters to lower case.
// Next, it removes stop words, which are words that do not add meaning to the text such as "the", "and", "a", etc.
// Finally, it counts the number of remaining words and prints the result.
// This tool can be used for various purposes such as analyzing text data, measuring writing proficiency, and more.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER_SIZE 1000000 // Maximum size of the text file

int main(int argc, char *argv[]) {
    char buffer[MAX_BUFFER_SIZE];
    char *stopwords[] = {"a", "an", "the", "and", "or", "but", "not", "of", "on", "in", "at", "to", "for", "by", "with", "from", "as", "then", "that", "this", "those", "these", "they", "it", "is", "are", "was", "were", "has", "have", "had", "can", "could", "will", "would", "should", "may", "might", "shall", "must", "be", "been", "being"}; // List of stop words
    int num_stopwords = sizeof(stopwords) / sizeof(char *); // Number of stop words
    int i, word_count = 0, skip_word;
    size_t buffer_size = MAX_BUFFER_SIZE;
    FILE *fp;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Read the file content into buffer
    fread(buffer, sizeof(char), MAX_BUFFER_SIZE, fp);

    // Replace punctuation marks with spaces
    for (i = 0; i < MAX_BUFFER_SIZE; i++) {
        if (ispunct(buffer[i])) {
            buffer[i] = ' ';
        } else {
            buffer[i] = tolower(buffer[i]);
        }
    }

    // Count the number of words
    char *token = strtok(buffer, " ");
    while (token != NULL) {
        skip_word = 0;
        for (i = 0; i < num_stopwords; i++) {
            if (strcmp(token, stopwords[i]) == 0) {
                skip_word = 1;
                break;
            }
        }
        if (!skip_word) {
            word_count++;
        }
        token = strtok(NULL, " ");
    }

    // Print the result
    printf("Number of words: %d\n", word_count);

    // Close the file
    if (fclose(fp) != 0) {
        perror("Error closing file");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}