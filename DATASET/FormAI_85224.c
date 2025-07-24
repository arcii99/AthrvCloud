//FormAI DATASET v1.0 Category: Text processing ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char text[100];
    printf("Enter some text:\n");
    fgets(text, 100, stdin);

    printf("Original text:\n");
    printf("%s\n", text);

    // Convert text to uppercase
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] -= 32;
        }
    }

    printf("Uppercase text:\n");
    printf("%s\n", text);

    // Count number of words in text
    int word_count = 1;
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == ' ' || text[i] == '\n') {
            word_count++;
        }
    }

    printf("Number of words: %d\n", word_count);

    // Reverse the text
    char reversed[100];
    int j = 0;
    for (int i = strlen(text) - 1; i >= 0; i--) {
        reversed[j++] = text[i];
    }
    reversed[strlen(text)] = '\0';

    printf("Reversed text:\n");
    printf("%s\n", reversed);

    return 0;
}