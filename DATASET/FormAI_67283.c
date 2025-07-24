//FormAI DATASET v1.0 Category: Spell checking ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50  // Maximum word length to be considered in the program
#define MAX_DICT_WORDS 5000  // Maximum number of words to be stored in dictionary

/**
 * This function takes an input string 'str' as parameter and returns a string with
 * all its characters converted to lowercase.
 **/
char* to_lower(char* str) {
    int i;
    char* lower_str = malloc(strlen(str) + 1);  // Allocate memory to store the lower case string
    // Convert each character to lower case and store in the new string
    for (i = 0; i < strlen(str); i++) {
        lower_str[i] = tolower(str[i]);
    }
    lower_str[i] = '\0';  // Add Null character at the end of the new string
    return lower_str;
}

int main() {
    char* dict_words[MAX_DICT_WORDS];  // Array to store dictionary words read from file
    char* filename = "dictionary.txt";  // Name of the file containing the dictionary words
    FILE* dict_file = fopen(filename, "r");  // Open file in read mode
    char word[MAX_WORD_LENGTH];  // Buffer to store user input word
    char* lower_word;  // Pointer to store lower case version of the user input word
    int num_dict_words = 0;  // Number of words read from dictionary file
    int i;  // Counter variable

    // Read dictionary file and store words in the dict_words array
    if (dict_file == NULL) {
        printf("Error: Failed to open file '%s'\n", filename);
        return 1;
    }
    while (fgets(word, sizeof(word), dict_file)) {
        word[strcspn(word, "\n")] = 0;  // Remove the newline character from the word
        dict_words[num_dict_words++] = strdup(word);  // Add the word to dictionary array
    }
    fclose(dict_file);  // Close the dictionary file

    // Get user input for the word to be checked
    printf("Enter a word to be checked: ");
    scanf("%s", word);

    lower_word = to_lower(word);  // Convert the user input word to lower case

    // Check if the input word is in the dictionary
    for (i = 0; i < num_dict_words; i++) {
        if (strcmp(lower_word, to_lower(dict_words[i])) == 0) {
            printf("'%s' is spelled correctly!\n", word);
            return 0;
        }
    }

    // If the input word does not match any word in the dictionary, print suggestions
    printf("'%s' is misspelled.\n", word);
    printf("Suggestions:\n");
    for (i = 0; i < num_dict_words; i++) {
        if (strstr(to_lower(dict_words[i]), lower_word) != NULL) {  // Check if the dictionary word contains the input word as a sub-string
            printf("%s\n", dict_words[i]);
        }
    }

    return 0;
}