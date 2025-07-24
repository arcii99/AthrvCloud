//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: brave
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 50

int main() {
    char input[1000];
    int freq[MAX_WORD_SIZE], i, j, len, count;

    // Initialize the frequency array
    for(i=0; i<MAX_WORD_SIZE; i++) {
        freq[i] = 0;
    }

    printf("Enter text to analyze:\n");
    fgets(input, 1000, stdin); // Read input from user

    // Loop through each character in the input
    len = strlen(input);
    i = 0;
    while(i < len) {
        char word[MAX_WORD_SIZE] = "";
        count = 0;

        // Get the next word
        while(isalpha(input[i])) {
            word[count] = tolower(input[i]);
            count++;
            i++;
        }
        i++;

        // Update the frequency of the word
        if(count > 0) {
            freq[count-1]++;
        }
    }

    // Print out the frequency table
    printf("Frequency table:\n");
    printf("%-10s%10s\n", "Word Size", "Frequency");
    for(i=0; i<MAX_WORD_SIZE; i++) {
        if(freq[i] > 0) {
            printf("%-10d%10d\n", i+1, freq[i]);
        }
    }

    return 0;
}