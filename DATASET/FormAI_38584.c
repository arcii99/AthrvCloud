//FormAI DATASET v1.0 Category: Word Count Tool ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wordCount(char* str) {
    int i, count = 0, word = 0;

    // loop through string characters
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\n') {
            if (word == 0) {
                count++;
                word = 1;
            }
        }
        else {
            word = 0;
        }
    }
    return count;
}

int main() {
    char inputStr[1000];

    // read input string
    printf("Enter string: ");
    fgets(inputStr, 1000, stdin);

    // get word count
    int count = wordCount(inputStr);

    // output result
    printf("Word count: %d\n", count);

    return 0;
}