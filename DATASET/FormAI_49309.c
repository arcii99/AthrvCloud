//FormAI DATASET v1.0 Category: Word Count Tool ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void countWords(char* inputString) {
    int i, count = 0;
    int state = 0; // 0 for outside word, 1 for inside word

    for (i = 0; i < strlen(inputString); i++) {
        if (inputString[i] == ' ' || inputString[i] == '\n' || inputString[i] == '\t') {
            state = 0;
        } else if (state == 0) {
            state = 1;
            count++;
        }
    }

    printf("Word count: %d\n", count);
}

int main() {
    char inputString[1000];

    printf("Enter a string with one or more words:\n");
    fgets(inputString, 1000, stdin);

    countWords(inputString);

    return 0;
}