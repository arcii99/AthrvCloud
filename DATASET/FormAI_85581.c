//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void countWords(char inputString[]);

int main() {
    char sentence[1000];

    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin);

    countWords(sentence);

    return 0;
}

void countWords(char inputString[]) {
    int count = 0;
    char* word = strtok(inputString, " ");

    while (word != NULL) {
        count++;
        word = strtok(NULL, " ");
    }

    printf("Total words in the sentence: %d\n", count);
}