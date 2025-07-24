//FormAI DATASET v1.0 Category: Word Count Tool ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char text[1000];
    int word_count = 0;

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    // Loop through each character in the text
    for (int i = 0; i < strlen(text); i++) {
        // If the character is a space, increment the word count
        if (text[i] == ' ') {
            word_count++;
        }
    }

    // If the last character in the text is not a space, increment the word count
    if (text[strlen(text) - 1] != ' ') {
        word_count++;
    }

    printf("The text contains %d words.\n", word_count);

    return 0;
}