//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Define constant for maximum word length
#define MAX_WORD_LEN 50

int main() {

    // Initialize variables to store input and word frequency
    char input[1000];
    int count = 0;
    int i, j, k;

    // Get user input
    printf("Enter input string: ");
    fgets(input, 1000, stdin);

    // Convert all characters to lowercase
    for(i = 0; i < strlen(input); i++) {
        input[i] = tolower(input[i]);
    }

    // Split input into individual words
    char words[100][MAX_WORD_LEN];
    for(i = 0; i < strlen(input); i++) {
        k = 0;

        // Skip any non-letter characters
        while(!isalpha(input[i]) && i < strlen(input)) {
            i++;
        }

        // Add letters to current word until a non-letter character is reached
        while(isalpha(input[i])) {
            words[count][k++] = input[i++];
        }

        // Terminate current word with null character
        words[count++][k] = '\0';
    }

    // Initialize array to store word frequency
    int freq[100] = {0};

    // Count frequency of each word
    for(i = 0; i < count; i++) {
        for(j = i+1; j < count; j++) {
            if(strcmp(words[i], words[j]) == 0) {
                freq[i]++;
                // Set frequency for matching word to -1 to avoid double-counting
                freq[j] = -1;
            }
        }
    }

    // Display word frequency
    printf("Word Frequency\n");
    for(i = 0; i < count; i++) {
        if(freq[i] != -1) {
            printf("%-15s %d\n", words[i], freq[i]+1);
        }
    }

    return 0;
}