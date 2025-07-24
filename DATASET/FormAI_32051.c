//FormAI DATASET v1.0 Category: File handling ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

int countWords(char *buffer);

int main(int argc, char *argv[]) {
    char buffer[BUFFER_SIZE];
    int wordCount = 0;
    FILE *fp;

    // Check whether the file name has been passed as an argument
    if (argc < 2) {
        printf("Error: File name missing\n");
        printf("Usage: %s <file name>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open the file
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Unable to open file '%s'\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Read the contents of the file
    while (fgets(buffer, BUFFER_SIZE, fp)) {
        wordCount += countWords(buffer);
    }

    // Close the file
    fclose(fp);

    printf("Number of words in file '%s': %d\n", argv[1], wordCount);

    return 0;
}

/**
 * Counts the number of words in a given buffer
 * @param buffer The buffer whose words need to be counted
 * @return The number of words in the buffer
 */
int countWords(char *buffer) {
    int count = 0;
    char *token;
    char delimiters[] = " \t\n\r\f\v"; // Word delimiters

    token = strtok(buffer, delimiters);
    while (token != NULL) {
        count++;
        token = strtok(NULL, delimiters);
    }

    return count;
}