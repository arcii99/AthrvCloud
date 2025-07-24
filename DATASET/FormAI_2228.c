//FormAI DATASET v1.0 Category: Text processing ; Style: introspective
/*

This C program reads a file, converts the text to uppercase and counts the occurrence of each word. The output is then sorted in descending order according to the frequency of occurrence.

*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Define a struct to hold the word and its count
struct word {
    char *string;
    int count;
};

int main(int argc, char **argv) {
    // Check if the file name was provided
    if (argc != 2) {
        printf("Usage: ./text_processor <filename>\n");
        return 1;
    }

    // Open the file
    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Unable to open file %s\n", argv[1]);
        return 1;
    }

    // Allocate memory for the word array
    struct word *words = malloc(sizeof(struct word));
    int num_words = 0;

    // Read the file
    char current_word[50];
    while (fscanf(fp, "%s", current_word) != EOF) {
        // Convert the word to uppercase
        for(int i = 0; current_word[i]; i++){
            current_word[i] = toupper(current_word[i]);
        }

        // Check if the word is already in the array
        int index = find_word_index(words, num_words, current_word);
        if (index == -1) {
            // Allocate memory for the new word
            struct word new_word;
            new_word.string = malloc(sizeof(current_word));
            strcpy(new_word.string, current_word);
            new_word.count = 1;

            // Add the new word to the array
            num_words++;
            words = realloc(words, num_words * sizeof(struct word));
            words[num_words - 1] = new_word;
        } else {
            // Increment the count of the existing word
            words[index].count++;
        }
    }

    // Close the file
    fclose(fp);

    // Sort the words in descending order according to the frequency of occurrence
    sort_words(words, num_words);

    // Print the output to the console
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].string, words[i].count);
    }

    // Free the memory used by the word array
    for (int i = 0; i < num_words; i++) {
        free(words[i].string);
    }
    free(words);

    return 0;
}

// Helper function to find the index of a word in the word array
int find_word_index(struct word *words, int num_words, char *string) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(words[i].string, string) == 0) {
            return i;
        }
    }
    return -1;
}

// Helper function to sort the word array in descending order according to the frequency of occurrence
void sort_words(struct word *words, int num_words) {
    for (int i = 0; i < num_words - 1; i++) {
        for (int j = 0; j < num_words - i - 1; j++) {
            if (words[j].count < words[j + 1].count) {
                // Swap the positions of the two words
                struct word temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }
}