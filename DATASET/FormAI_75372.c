//FormAI DATASET v1.0 Category: Spell checking ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_MISSPELLINGS 10

char dictionary[][MAX_WORD_LENGTH] = {"apple", "banana", "cherry", "orange", "grape", "kiwi", "lemon", "lime", "mango", "pear"};

int numWords = sizeof(dictionary)/sizeof(dictionary[0]);

char misspellings[MAX_MISSPELLINGS][MAX_WORD_LENGTH];

int numMisspellings = 0;

int isMisspelled(char *word) {
    int i;
    for (i = 0; i < numWords; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 0;
        }
    }
    return 1;
}

void addMisspelling(char *word) {
    strcpy(misspellings[numMisspellings], word);
    numMisspellings++;
}

void checkWord(char *word) {
    if (isMisspelled(word)) {
        addMisspelling(word);
    }
}

void checkLine(char *line) {
    char *token;
    char *delim = " ,.-\n";
    token = strtok(line, delim);
    while (token != NULL) {
        checkWord(token);
        token = strtok(NULL, delim);
    }
}

void printMisspellings() {
    if (numMisspellings > 0) {
        printf("The following words are misspelled:\n");
        int i;
        for (i = 0; i < numMisspellings; i++) {
            printf("%s\n", misspellings[i]);
        }
    } else {
        printf("No misspellings found.\n");
    }
}

void toLowerCase(char *string) {
    int i;
    for (i = 0; string[i]; i++) {
        string[i] = tolower(string[i]);
    }
}

int main() {
    char line[100];
    printf("Enter a sentence: ");
    fgets(line, 100, stdin);
    toLowerCase(line);
    checkLine(line);
    printMisspellings();
    return 0;
}