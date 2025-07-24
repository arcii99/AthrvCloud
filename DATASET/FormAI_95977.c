//FormAI DATASET v1.0 Category: Text processing ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char text[1000];
    int textLength;

    printf("Please enter some text: ");
    fgets(text, 1000, stdin);

    textLength = strlen(text);

    // Count the number of non-whitespace characters
    int nonWhiteSpaceCount = 0;
    for (int i = 0; i < textLength; i++) {
        if (text[i] != ' ' && text[i] != '\n' && text[i] != '\r' && text[i] != '\t') {
            nonWhiteSpaceCount++;
        }
    }

    printf("\n----------------------\n");
    printf("Text processing summary\n");
    printf("----------------------\n");
    printf("Input text: %s", text);
    printf("Number of characters: %d\n", textLength - 1);
    printf("Number of non-whitespace characters: %d\n", nonWhiteSpaceCount);

    // Count the frequency of each character
    int frequency[256] = {0};
    for (int i = 0; i < textLength; i++) {
        frequency[(int)text[i]]++;
    }

    printf("\nCharacter frequencies:\n");
    printf("----------------------\n");
    for (int i = 0; i < 256; i++) {
        if (frequency[i] != 0) {
            printf("%c: %d\n", (char)i, frequency[i]);
        }
    }

    return 0;
}