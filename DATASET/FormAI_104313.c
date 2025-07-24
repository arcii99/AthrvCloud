//FormAI DATASET v1.0 Category: Spell checking ; Style: Romeo and Juliet
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_DICTIONARY_SIZE 1000

void toLowerCase(char word[]) {
    int i = 0;
    while (word[i]) {
        word[i] = tolower(word[i]);
        i++;
    }
}

int checkWord(char word[], char dictionary[][MAX_WORD_LENGTH], int n) {
    toLowerCase(word);
    for (int i = 0; i < n; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char dictionary[MAX_DICTIONARY_SIZE][MAX_WORD_LENGTH];
    int n = 0;
    // Populate dictionary from file
    FILE* file = fopen("dictionary.txt", "r");
    if (file == NULL) {
        printf("Error opening dictionary file\n");
        return 1;
    }
    char buffer[MAX_WORD_LENGTH];
    while (fgets(buffer, MAX_WORD_LENGTH, file)) {
        buffer[strcspn(buffer, "\n")] = 0; // remove newline character
        strcpy(dictionary[n], buffer);
        n++;
    }
    fclose(file);

    // Input sentence to check
    printf("O Romeo, wherefore art thou Romeo?\nEnter a sentence to check for spelling errors: ");
    char sentence[MAX_DICTIONARY_SIZE * MAX_WORD_LENGTH]; // assume worst case scenario
    fgets(sentence, MAX_DICTIONARY_SIZE * MAX_WORD_LENGTH, stdin);
    printf("Checking...\n");

    // Check each word in sentence
    char delimiters[] = " \t\r\n.,;:\"?!(){}[]";
    char* word = strtok(sentence, delimiters);
    while (word != NULL) {
        if (!checkWord(word, dictionary, n)) {
            printf("Oh no! '%s' is not part of our dictionary.\n", word);
        }
        word = strtok(NULL, delimiters);
    }

    printf("Hark! Thy spelling hath been checked!\n");
    return 0;
}