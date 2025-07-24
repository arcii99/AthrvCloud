//FormAI DATASET v1.0 Category: Spell checking ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a word is in the dictionary
// Returns 1 if it is, 0 if it is not
int checkDictionary(char *word, char **dictionary, int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a word is misspelled
// Returns 1 if it is, 0 if it is not
int checkMisspellings(char *word, char **dictionary, int size) {
    int len = strlen(word);
    char *temp = malloc(len + 1);
    if (temp == NULL) {
        printf("Error allocating memory");
        exit(1);
    }
    // Check each letter, one at a time, with a letter removed
    for (int i = 0; i < len; i++) {
        int index = 0;
        for (int j = 0; j < len; j++) {
            if (j != i) {
                temp[index++] = word[j];
            }
        }
        temp[index] = '\0';
        if (checkDictionary(temp, dictionary, size)) {
            free(temp);
            return 1;
        }
    }
    // Check each letter, one at a time, with a different letter substituted in
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 26; j++) {
            temp[i] = 'a' + j;
            if (checkDictionary(temp, dictionary, size)) {
                free(temp);
                return 1;
            }
        }
        temp[i] = word[i];
    }
    // Check each letter, one at a time, with a letter added in
    for (int i = 0; i <= len; i++) {
        int index = 0;
        for (int j = 0; j < len; j++) {
            if (j == i) {
                temp[index++] = 'a';
            }
            temp[index++] = word[j];
        }
        temp[index] = '\0';
        if (checkDictionary(temp, dictionary, size)) {
            free(temp);
            return 1;
        }
    }
    free(temp);
    return 0;
}

int main() {
    // Define the dictionary and its size
    char *dictionary[] = {"apple", "banana", "cherry", "date", "elderberry",
                          "fig", "grape", "honeydew", "kiwi", "lemon"};
    int dictionarySize = 10;

    printf("Enter a sentence to be spell checked: ");

    // Get the sentence to be spell checked
    char sentence[100];
    fgets(sentence, 100, stdin);

    // Parse the sentence and check each word
    char *word = strtok(sentence, " ,.-\n");
    while (word != NULL) {
        // Convert the word to lowercase
        int len = strlen(word);
        for (int i = 0; i < len; i++) {
            word[i] = tolower(word[i]);
        }
        // Check if the word is in the dictionary or if it has any misspellings
        if (!checkDictionary(word, dictionary, dictionarySize) &&
            !checkMisspellings(word, dictionary, dictionarySize)) {
            printf("%s is misspelled.\n", word);
        }
        word = strtok(NULL, " ,.-\n");
    }

    return 0;
}