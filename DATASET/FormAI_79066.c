//FormAI DATASET v1.0 Category: Spell checking ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int is_word(char* str) { // Function to check if a string is a valid word
    for(int i=0; str[i] != '\0'; i++) {
        if(!isalpha(str[i])) // If the string contains non-alphabetic characters, it's not a word
            return 0;
    }
    return 1;
}

void check_spelling(char *text, char *dictionary_path) {
    FILE *dict = fopen(dictionary_path, "r"); // Opening the dictionary file
    char dict_word[50];
    int error_count = 0;
    while(fgets(dict_word, 50, dict) != NULL) { // Reading the dictionary line by line
        strtok(dict_word, "\n"); // Remove '\n' character from the current word in the dictionary
        if(strstr(text, dict_word) != NULL) { // If the word from the dictionary is in the text
            continue;
        }
        if(is_word(dict_word)) { // If the word from the dictionary is a valid word
            printf("Did you mean: %s?\n", dict_word); // Suggest the corrected spelling
            error_count++;
        }
    }
    if(error_count == 0)
        printf("No errors found.\n");
    fclose(dict);
}

int main() {
    char text[500];
    char dictionary_path[100];
    printf("Enter the text to check spelling:\n");
    fgets(text, 500, stdin);
    strtok(text, "\n"); // Remove '\n' character at the end of the entered text
    printf("Enter the path to the dictionary file:\n");
    fgets(dictionary_path, 100, stdin);
    strtok(dictionary_path, "\n"); // Remove '\n' character at the end of the entered path
    check_spelling(text, dictionary_path);
    return 0;
}