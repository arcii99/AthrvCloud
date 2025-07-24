//FormAI DATASET v1.0 Category: Spell checking ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define MAX_DICTIONARY_SIZE 1000

char dictionary[MAX_DICTIONARY_SIZE][MAX_WORD_LENGTH];
int dictionarySize = 0;

void loadDictionary(char fileName[]) {
    FILE* pFile;
    char buffer[MAX_WORD_LENGTH];
      
    pFile = fopen(fileName, "r");
    if (pFile == NULL) {
      printf("Error: Could not open file %s\n", fileName);
      exit(1);
    }

    while (fgets(buffer, MAX_WORD_LENGTH, pFile) != NULL) {
      // Remove trailing newline
      buffer[strcspn(buffer, "\n")] = 0;
      strcpy(dictionary[dictionarySize], buffer);
      dictionarySize++;
    }
    fclose(pFile);
}

int isWordInDictionary(char* word) {
    int i = 0;
    for (i = 0; i < dictionarySize; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

void checkSpelling(char* text) {
    char word[MAX_WORD_LENGTH];
    int wordLength = 0;
    int i = 0;
    int j = 0;
    
    while (text[i]) {
        if (isspace(text[i]) || ispunct(text[i])) {
            if (wordLength > 0) {
                word[wordLength] = '\0';
                if (!isWordInDictionary(word)) {
                    printf("Unknown word: %s\n", word);
                }
                wordLength = 0;
            }
        } else {
            word[wordLength] = tolower(text[i]);
            wordLength++;
        }
        i++;
    }
}

int main() {
    loadDictionary("dictionary.txt");
    char text[] = "Ther may bee menny speling errrs in this textt, so I hope this spell chekker wil find them.";
    checkSpelling(text);
    return 0;
}