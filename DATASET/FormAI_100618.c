//FormAI DATASET v1.0 Category: Word Count Tool ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[500];
    int count = 0;
    printf("Enter a sentence to count the number of words: ");
    fgets(input, 500, stdin); // Get input from user

    // Remove any trailing newline
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }

    // Loop through each character in input
    for (int i = 0; input[i] != '\0'; i++) {
        // If space or tab is encountered, increment count
        if (input[i] == ' ' || input[i] == '\t') {
            count++;
        }
    }

    // Output the total number of words
    printf("Total number of words in the sentence: %d\n", count + 1);
    return 0;
}