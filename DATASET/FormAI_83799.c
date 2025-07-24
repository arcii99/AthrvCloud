//FormAI DATASET v1.0 Category: Text processing ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* findWord(const char* sentence, const char* word) {
    int sentenceLen = strlen(sentence);
    int wordLen = strlen(word);
    int wordIndex = 0;
    char* result = NULL;

    for (int i = 0; i < sentenceLen; i++) {
        if (sentence[i] == word[wordIndex]) {
            wordIndex++;

            if (wordIndex == wordLen) {
                result = (char*) malloc(sizeof(char) * wordLen);
                strncpy(result, &sentence[i - wordIndex + 1], wordLen);
                result[wordLen] = '\0';
                break;
            }
        }
        else {
            wordIndex = 0;
        }
    }

    return result;
}

int main() {
    char sentence[100] = "The world has been devastated by nuclear war";
    char word[10] = "devastate";
    char* foundWord = findWord(sentence, word);

    if (foundWord != NULL) {
        printf("Found word: %s\n", foundWord);
    }
    else {
        printf("Word not found\n");
    }

    free(foundWord);
    foundWord = NULL;

    return 0;
}