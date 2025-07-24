//FormAI DATASET v1.0 Category: Word Count Tool ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 500 // Maximum length of a word in the input file.
#define MAX_MAP_LENGTH 100000 // Maximum number of unique words expected.

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        exit(1);
    }

    char* filename = argv[1];
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    // Initialize the word map.
    char** word_map = calloc(MAX_MAP_LENGTH, sizeof(char*));
    int* word_count = calloc(MAX_MAP_LENGTH, sizeof(int));
    int map_size = 0;

    // Read from file and populate the word map.
    char current_word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", current_word) == 1) {
        // Convert the word to lowercase.
        int len = strlen(current_word);
        for (int i = 0; i < len; i++) {
            current_word[i] = tolower(current_word[i]);
        }

        // Check if the word is already in the map.
        int found = 0;
        for (int i = 0; i < map_size; i++) {
            if (strcmp(word_map[i], current_word) == 0) {
                word_count[i]++;
                found = 1;
                break;
            }
        }

        // Add the word to the map if it's not already in there.
        if (!found) {
            word_map[map_size] = calloc(len+1, sizeof(char));
            strcpy(word_map[map_size], current_word);
            word_count[map_size] = 1;
            map_size++;
        }
    }

    // Print the word count.
    printf("Total words in file: %d\n", map_size);
    printf("Word Count\n");
    printf("============\n");
    for (int i = 0; i < map_size; i++) {
        printf("%s: %d\n", word_map[i], word_count[i]);
        free(word_map[i]);
    }

    // Clean up and exit.
    fclose(fp);
    free(word_map);
    free(word_count);
    return 0;
}