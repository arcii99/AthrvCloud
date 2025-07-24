//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[1000];
    int freq[26] = {0};

    printf("Enter a string: ");
    scanf("%[^\n]", input);

    // Remove any non-alphabetic characters from the string
    for (int i = 0; i < strlen(input); i++) {
        if (!isalpha(input[i])) {
            memmove(&input[i], &input[i + 1], strlen(input) - i);
            i--;
        }
    }

    // Convert all characters to lowercase for case-insensitivity
    for (int i = 0; i < strlen(input); i++) {
        if (isupper(input[i])) {
            input[i] = tolower(input[i]);
        }
    }

    // Count the frequency of each letter in the string
    for (int i = 0; i < strlen(input); i++) {
        freq[input[i] - 'a']++;
    }

    // Print out the frequency of each letter
    printf("\nLetter frequencies:\n");
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            printf("%c: %d\n", i + 'a', freq[i]);
        }
    }

    return 0;
}