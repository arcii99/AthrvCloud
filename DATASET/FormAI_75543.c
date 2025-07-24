//FormAI DATASET v1.0 Category: Word Count Tool ; Style: inquisitive
#include <stdio.h>
#include <string.h>

int main() {
    char input[1000];
    int words = 0;

    printf("Enter a sentence: ");
    fgets(input, sizeof(input), stdin);

    // Find number of words
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == ' ') {
            words++;
        }
    }

    words++; // Increment for last word

    printf("The number of words in the sentence is: %d\n", words);

    return 0;
}