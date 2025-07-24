//FormAI DATASET v1.0 Category: Word Count Tool ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countWords(char sentence[]);

int main() {
    char input[1000];
    int wordCount;

    printf("Enter a sentence:\n");
    fgets(input, 1000, stdin); // Get user input

    wordCount = countWords(input);

    printf("\nWord Count: %d", wordCount); // Display word count

    return 0;
}

int countWords(char sentence[]) {
    int count = 0;
    char space = ' ';

    for(int i = 0; i < strlen(sentence); i++) {
        if(sentence[i] == space || sentence[i] == '\n') count++; // If space or new line found, increment word count
    }
    return count+1; // Add 1 to account for last word in sentence
}