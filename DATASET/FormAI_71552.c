//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

int countWords(char string[]) {
    int i, wordCount = 0;
    int len = strlen(string);
    int inWord = 0;

    for(i = 0; i < len; i++) {
        if(string[i] == ' ' || string[i] == '\t' || string[i] == '\n')
            inWord = 0;
        else if(!inWord) {
            inWord = 1;
            wordCount++;
        }
    }

    return wordCount;
}

int main() {
    char string[1000];
    printf("Enter a string: ");
    fgets(string, 1000, stdin);

    int numWords = countWords(string);

    printf("Word count: %d\n", numWords);

    return 0;
}