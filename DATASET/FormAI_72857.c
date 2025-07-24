//FormAI DATASET v1.0 Category: Text processing ; Style: inquisitive
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char sentence[100];
    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin);

    int wordCount = 1, vowelCount = 0, consonantCount = 0;
    for (int i = 0; i < strlen(sentence); i++) {
        // Counting words
        if (isspace(sentence[i])) {
            wordCount++;
        }

        // Counting vowels and consonants
        char letter = tolower(sentence[i]);
        if (isalpha(letter)) {
            if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u') {
                vowelCount++;
            } else {
                consonantCount++;
            }
        }
    }

    // Outputting results
    printf("Your sentence contains %d words.\n", wordCount);
    printf("Your sentence contains %d vowels and %d consonants.\n", vowelCount, consonantCount);

    return 0;
}