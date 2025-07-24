//FormAI DATASET v1.0 Category: Text processing ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process_file(FILE* fp, const char* word_to_replace, const char* new_word, int* count) {
    const int BUFFER_SIZE = 1024;
    char buffer[BUFFER_SIZE];
    char* ptr;

    // Read a line from the file and check for EOF
    if (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
        // Recursively process the rest of the file
        process_file(fp, word_to_replace, new_word, count);

        // Replace all occurrences of the word in the buffer
        while ((ptr = strstr(buffer, word_to_replace)) != NULL) {
            (*count)++;
            memmove(ptr + strlen(new_word), ptr + strlen(word_to_replace), strlen(ptr + strlen(word_to_replace)) + 1);
            memcpy(ptr, new_word, strlen(new_word));
        }

        // Write the modified line to the file
        fputs(buffer, fp);
    }
}

int main(int argc, char const *argv[]) {
    if (argc < 4) {
        printf("Usage: %s file word_to_replace new_word\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char* file_name = argv[1];
    const char* word_to_replace = argv[2];
    const char* new_word = argv[3];
    int count = 0;

    // Open the file for reading and writing
    FILE* fp = fopen(file_name, "r+");
    if (fp == NULL) {
        printf("Error: Failed to open file %s\n", file_name);
        exit(EXIT_FAILURE);
    }

    // Recursively process the file
    process_file(fp, word_to_replace, new_word, &count);

    // Close the file and print the number of replacements
    fclose(fp);
    printf("Replaced %d occurrences of '%s' with '%s' in file %s\n", count, word_to_replace, new_word, file_name);

    return 0;
}