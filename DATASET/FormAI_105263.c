//FormAI DATASET v1.0 Category: Spell checking ; Style: Linus Torvalds
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_DICTIONARY_WORDS 5000

int lineCount = 0;
int wordCount = 0;
char dictionary[MAX_DICTIONARY_WORDS][MAX_WORD_LENGTH];
char words[MAX_DICTIONARY_WORDS][MAX_WORD_LENGTH];

void readDictionary() {
    FILE *file = fopen("/usr/share/dict/words", "r");
    if (file) {
        while (fgets(dictionary[wordCount], sizeof(dictionary[wordCount]), file)) {
            dictionary[wordCount][strcspn(dictionary[wordCount], "\n")] = 0;
            wordCount++;
        }
        fclose(file);
    } else {
        printf("Error: unable to open dictionary file!");
    }
}

int checkDictionary(char *word) {
    for (int i = 0; i < wordCount; i++) {
        if (strcasecmp(dictionary[i], word) == 0)
            return 1;
    }
    return 0;
}

void spellCheck(char *line) {
    char *token;
    token = strtok(line, " \t\n\r");
    while (token != NULL) {
        if (!checkDictionary(token)) {
            printf("Line %d: %s is misspelled.\n", lineCount, token);
        }
        token = strtok(NULL, " \t\n\r");
    }
}

int main() {
    readDictionary();

    char line[MAX_DICTIONARY_WORDS];
    while (fgets(line, sizeof(line), stdin)) {
        lineCount++;
        spellCheck(line);
    }

    return 0;
}