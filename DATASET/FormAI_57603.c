//FormAI DATASET v1.0 Category: Spell checking ; Style: secure
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 50
#define DICTIONARY_FILE "dictionary.txt"
#define USER_INPUT_FILE "user_input.txt"

int main() {
    // Load the dictionary file into memory
    FILE* dict_file = fopen(DICTIONARY_FILE, "r");
    if (dict_file == NULL) {
        printf("Error: Unable to open dictionary file!\n");
        return 1;
    }
    char dictionary[10000][MAX_WORD_LEN];
    int num_words = 0;
    char buf[MAX_WORD_LEN];
    while (fgets(buf, MAX_WORD_LEN, dict_file)) {
        buf[strcspn(buf, "\n")] = 0;  // Strip newline character
        strcpy(dictionary[num_words], buf);
        num_words++;
    }
    fclose(dict_file);

    // Load the user input file into memory
    FILE* input_file = fopen(USER_INPUT_FILE, "r");
    if (input_file == NULL) {
        printf("Error: Unable to open input file!\n");
        return 1;
    }
    char user_input[MAX_WORD_LEN];
    while (fgets(user_input, MAX_WORD_LEN, input_file)) {
        user_input[strcspn(user_input, "\n")] = 0;  // Strip newline character

        // Make the input lowercase
        for (int i = 0; i < strlen(user_input); i++) {
            user_input[i] = tolower(user_input[i]);
        }

        // Check if the input is in the dictionary
        int in_dictionary = 0;
        for (int i = 0; i < num_words; i++) {
            if (strcmp(user_input, dictionary[i]) == 0) {
                in_dictionary = 1;
                break;
            }
        }

        // Print the result
        if (in_dictionary) {
            printf("%s is spelled correctly.\n", user_input);
        } else {
            printf("%s is misspelled!\n", user_input);
        }
    }
    fclose(input_file);

    return 0;
}