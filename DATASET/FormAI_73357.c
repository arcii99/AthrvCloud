//FormAI DATASET v1.0 Category: Spell checking ; Style: peaceful
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_DICTIONARY_SIZE 10000

void readDictionary(char **dictionary) {
    FILE *fp = fopen("dictionary.txt", "r");
    if(fp == NULL) {
        printf("Could not open dictionary\n");
        exit(1);
    }

    int index = 0;
    char word[MAX_WORD_LENGTH];

    while(fgets(word, MAX_WORD_LENGTH, fp) != NULL) {
        word[strcspn(word, "\n")] = 0;
        dictionary[index] = malloc(strlen(word) + 1);
        strcpy(dictionary[index], word);
        index++;
    }
    fclose(fp);
}

bool isInDictionary(char *word, char **dictionary, int dictionarySize) {
    for(int i = 0; i < dictionarySize; i++) {
        if(strcmp(word, dictionary[i]) == 0) {
            return true;
        }
    }
    return false;
}

void checkWord(char *word, char **dictionary, int dictionarySize) {
    int length = strlen(word);

    if(length > MAX_WORD_LENGTH) {
        printf("Error: Maximum word length exceeded.\n");
        return;
    }

    for(int i = 0; i < length; i++) {
        if(!isalpha(word[i])) {
            printf("Error: Word cannot contain non-alphabetic characters\n");
            return;
        }
        word[i] = tolower(word[i]);
    }

    if(isInDictionary(word, dictionary, dictionarySize)) {
        printf("%s is spelled correctly.\n", word);
    } else {
        printf("%s is misspelled.\n", word);
    }
}

int main() {
    char *dictionary[MAX_DICTIONARY_SIZE];
    int dictionarySize = 0;

    readDictionary(dictionary);

    char word[MAX_WORD_LENGTH];

    printf("Enter a word to spell check: ");
    scanf("%s", word);

    checkWord(word, dictionary, dictionarySize);
    
    for(int i = 0; i < dictionarySize; i++) {
        free(dictionary[i]);
    }

    return 0;
}