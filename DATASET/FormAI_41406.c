//FormAI DATASET v1.0 Category: Text processing ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char text[1000], word[100], replace[100];
    printf("Enter some text: ");
    fgets(text, 1000, stdin); // fgets() allows input with spaces
    printf("Enter the word to replace: ");
    scanf("%s", word);
    printf("Enter the replacement word: ");
    scanf("%s", replace);

    int textLength = strlen(text);
    int wordLength = strlen(word);
    int replaceLength = strlen(replace);

    // Traverse through the text string
    for (int i = 0; i < textLength; i++) {
        int match = 1;
        // Check if current word matches with the given word
        for (int j = 0; j < wordLength; j++) {
            if (text[i+j] != word[j]) {
                match = 0;
                break;
            }
        }
        // If match found, replace the word with the given replacement
        if (match) {
            // First, shift the remaining text by replaceLength
            for (int k = textLength-1; k >= i+wordLength; k--) {
                text[k+replaceLength-wordLength] = text[k];
            }
            // Second, copy the replacement word
            for (int k = 0; k < replaceLength; k++) {
                text[i+k] = replace[k];
            }
            // Update textLength accordingly
            textLength += replaceLength-wordLength;
        }
    }

    printf("\nAfter replacement: %s", text);

    return 0;
}