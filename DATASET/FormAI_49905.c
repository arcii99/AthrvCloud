//FormAI DATASET v1.0 Category: Text Summarizer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXSTRING 1000
#define MAXWORDS 100

void removePunctuation(char *string) {
    int i, j = 0;

    for (i = 0; string[i] != '\0'; i++) {
        if (ispunct(string[i])) {
            continue;
        }
        string[j++] = tolower(string[i]);
    }
    string[j] = '\0';
}

int isStopWord(char *string) {
    char *stopWords[] = {"a", "an", "and", "are", "as", "at", "be", "by", "for", "from", "has", "he", "in", "is", "it", "its", "of", "on", "that", "the", "to", "was", "were", "will", "with"};

    int i;
    int size = sizeof(stopWords) / sizeof(stopWords[0]);
    for (i = 0; i < size; i++) {
        if (strcmp(stopWords[i], string) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char inputString[MAXSTRING];
    printf("Enter a string: ");
    fgets(inputString, MAXSTRING, stdin);

    int wordsCount = 0;
    char *words[MAXWORDS];
    char *word = strtok(inputString, " ");
    while (word != NULL) {
        if (isStopWord(word)) {
            word = strtok(NULL, " ");
            continue;
        }
        removePunctuation(word);
        words[wordsCount++] = strdup(word);
        word = strtok(NULL, " ");
    }

    int maxFrequency = 0;
    char *maxWord;
    int i, j;
    for (i = 0; i < wordsCount; i++) {
        int currentFrequency = 1;
        if (words[i] == NULL) {
            continue;
        }
        for (j = i + 1; j < wordsCount; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                currentFrequency++;
                words[j] = NULL;
            }
        }
        if (currentFrequency > maxFrequency) {
            maxFrequency = currentFrequency;
            maxWord = words[i];
        }
    }

    printf("The most frequent word is: %s\n", maxWord);

    for (i = 0; i < wordsCount; i++) {
        free(words[i]);
    }

    return 0;
}