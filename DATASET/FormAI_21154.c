//FormAI DATASET v1.0 Category: Text processing ; Style: asynchronous
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024 // Buffer size for reading file contents
#define MAX_LINES 100 // Maximum number of lines to process

// Asynchronous function to count the number of occurences of a word in the given text
void word_count(char *word, char *text, int *count) {
    char *pos = text; // Position to start searching for word
    int len = strlen(word); // Length of word to search for
    while ((pos = strstr(pos, word))) { // Increment pos to next occurence of word in text
        // Check if found word is a separate word and not a substring of a longer word
        if ((pos == text || !isalnum(*(pos-1))) && (!isalnum(*(pos+len)))) { 
            (*count)++; // Increment word count
        }
        pos++; // Increment pos
    }
}

// Asynchronous function to read file contents and count the number of occurences of a word in each line
void process_lines(char *filename, char *word, int *counts, int *num_lines) {
    char buffer[BUFFER_SIZE]; // Buffer to read file contents
    int fd = open(filename, O_RDONLY); // Open file in read mode
    int line_count = 0; // Counter for number of lines processed
    int n; // Number of bytes read by read() system call
    bool newline = true; // Used to track if current character is at the start of a new line
    char *line_start = buffer; // Pointer to start of current line in buffer
    while ((n = read(fd, buffer, BUFFER_SIZE)) > 0) { // Read bytes into buffer
        for (int i = 0; i < n; i++) { // Iterate through buffer character by character
            if (newline) { // If current character is at start of a new line
                newline = false; // Reset newline flag
                line_start = buffer+i; // Set line_start pointer to current character
                line_count++; // Increment line count
                if (line_count > MAX_LINES) { // If maximum number of lines has been reached
                    close(fd); // Close file
                    (*num_lines) = MAX_LINES; // Set num_lines variable
                    return; // Exit function
                }
            }
            if (buffer[i] == '\n') { // If current character is a newline character
                *line_start = '\0'; // Set end of line marker at the previous character
                int count = 0; // Initialize word count
                word_count(word, line_start, &count); // Call word_count() function asynchronously
                counts[line_count-1] = count; // Set word count for current line in counts array
                newline = true; // Set newline flag
            }
        }
        memset(buffer, 0, BUFFER_SIZE); // Reset buffer to 0
    }
    close(fd); // Close file
    (*num_lines) = line_count; // Set num_lines variable
}

int main() {
    char filename[] = "input.txt";
    char word[] = "apple";
    int counts[MAX_LINES] = {0};
    int num_lines = 0;
    process_lines(filename, word, counts, &num_lines); // Call process_lines() function asynchronously
    printf("Processed %d lines\n", num_lines);
    printf("Word count for each line:\n");
    for (int i = 0; i < num_lines; i++) {
        printf("Line %d: %d\n", i+1, counts[i]);
    }
    return 0;
}