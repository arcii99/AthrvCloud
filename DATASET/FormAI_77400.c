//FormAI DATASET v1.0 Category: Word Count Tool ; Style: creative
#include <stdio.h>
#include <ctype.h>

int main() {
    int c, count = 0, in_word = 0;
    printf("Enter a sentence: ");

    while ((c = getchar()) != EOF) {
        if (isspace(c) || ispunct(c)) { // Check for whitespace or punctuation
            if (in_word) { // If we were counting a word, increment count
                count++;
                in_word = 0; // Set in_word back to 0 for new word
            }
        } else {
            in_word = 1; // We're in a word, so set in_word to true
        }
    }

    if (in_word) { // Check if last character was part of a word
        count++; // Increment count if last character was part of a word
    }

    printf("\nWord count: %d", count);
    return 0;
}