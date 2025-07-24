//FormAI DATASET v1.0 Category: Word Count Tool ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[1000]; // create input array with maximum size of 1000
    int wordCount = 0;

    printf("Enter a sentence: ");
    fgets(input, 1000, stdin); // get input from user

    // iterate through each character in the input array
    for (int i = 0; i < strlen(input); i++) {
        // if current character is a whitespace and previous character is not a whitespace, increment word count
        if (isspace(input[i]) && !isspace(input[i-1])) {
            wordCount++;
        }
    }

    // final check for word count increment if string does not end in a whitespace
    if (!isspace(input[strlen(input)-1])) {
        wordCount++;
    }
    
    printf("Word count: %d\n", wordCount);

    return 0;
}