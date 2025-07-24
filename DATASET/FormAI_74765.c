//FormAI DATASET v1.0 Category: Spell checking ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// function to check if a character is a letter or not
int is_letter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// function to convert a word to lowercase
void to_lowercase(char *word) {
    int i = 0;
    while (word[i]) {
        word[i] = tolower(word[i]);
        i++;
    }
}

int main() {
    // open the dictionary file for reading
    FILE *dict_file = fopen("dictionary.txt", "r");
    if (!dict_file) {
        printf("Error: could not open dictionary file\n");
        return 1;
    }

    // read in the contents of the dictionary file
    char dictionary_text[10000];
    char line[100];
    while (fgets(line, 100, dict_file)) {
        strcat(dictionary_text, line);
    }

    // split the dictionary text into individual words
    char *dictionary_words[10000];
    dictionary_words[0] = strtok(dictionary_text, " \n");
    int i = 0;
    while (dictionary_words[i]) {
        i++;
        dictionary_words[i] = strtok(NULL, " \n");
    }

    // prompt the user to enter a word or sentence to check
    printf("Enter a word or sentence to check the spelling of: ");
    char input[100];
    fgets(input, 100, stdin);

    // split the input into individual words
    char *input_words[100];
    input_words[0] = strtok(input, " \n");
    i = 0;
    while (input_words[i]) {
        i++;
        input_words[i] = strtok(NULL, " \n");
    }

    // loop through each input word and check if it is in the dictionary
    for (int j = 0; j < i; j++) {
        // convert the input word to lowercase
        to_lowercase(input_words[j]);

        // check if the input word is in the dictionary
        int found = 0;
        for (int k = 0; k < sizeof(dictionary_words) / sizeof(dictionary_words[0]); k++) {
            if (dictionary_words[k]) {
                char dict_word_lowercase[100];
                strcpy(dict_word_lowercase, dictionary_words[k]);
                to_lowercase(dict_word_lowercase);
                if (strcmp(dict_word_lowercase, input_words[j]) == 0) {
                    found = 1;
                    break;
                }
            }
        }

        // if the input word is not in the dictionary, print a message
        if (!found) {
            printf("Misspelled word: %s\n", input_words[j]);
        }
    }

    // close the dictionary file
    fclose(dict_file);

    return 0;
}