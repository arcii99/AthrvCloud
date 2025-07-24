//FormAI DATASET v1.0 Category: Word Count Tool ; Style: thoughtful
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[1000];
    int i, len, wordCount=0;

    // Prompt user for input text
    printf("Enter the text: ");
    fgets(input, 1000, stdin);

    // Get length of input string
    len = strlen(input);

    // Count number of words
    for(i=0; i<len; i++) {
        if(isalpha(input[i])) {
            while(isalpha(input[i])) i++;
            wordCount++;
        }
    }

    printf("Number of words in the input text: %d\n", wordCount);

    return 0;
}