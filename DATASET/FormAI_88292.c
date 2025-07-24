//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 1000
#define MAX_WORD_LENGTH 50

int main() {
    char inputString[MAX_STRING_LENGTH], word[MAX_WORD_LENGTH];
    int wordCount = 0, i, len;

    printf("Enter a string:\n");
    fgets(inputString, MAX_STRING_LENGTH, stdin);
    
    len = strlen(inputString);
    if (len > 0 && inputString[len-1] == '\n') {
        inputString[len-1] = '\0';
    }

    for (i = 0; inputString[i] != '\0'; i++) {
        if (isalnum(inputString[i])) {
            word[wordCount++] = tolower(inputString[i]);
        } else if (wordCount > 0) {
            word[wordCount] = '\0';
            printf("%s\n", word);
            wordCount = 0;
        }
    }

    if (wordCount > 0) {
        word[wordCount] = '\0';
        printf("%s\n", word);
    }

    return 0;
}