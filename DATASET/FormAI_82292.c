//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: expert-level
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_LENGTH 1000

int main() {
    char input[MAX_LENGTH];
    printf("Please enter your text: ");
    fgets(input, MAX_LENGTH, stdin);

    int frequency[26] = {0}; // initialize the frequency array to 0

    int i = 0;
    while (input[i] != '\0') {
        if (isalpha(input[i])) { // ensure that only letters are counted
            char current = tolower(input[i]); // convert to lowercase so that capital and
            // lowercase versions of the same letter are treated as the same
            int index = current - 'a'; // calculate the index for the current letter
            frequency[index]++; // increment the count for that letter
        }
        i++;
    }

    printf("\nThe frequency of each letter in your text is:\n");

    for (int j = 0; j < 26; j++) {
        char letter = j + 'a'; // calculate the letter for the current index
        printf("%c: %d\n", letter, frequency[j]); // print out the frequency for that letter
    }

    return 0;
}