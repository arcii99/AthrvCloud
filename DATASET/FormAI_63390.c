//FormAI DATASET v1.0 Category: Text processing ; Style: artistic
#include <stdio.h>
#include <string.h>
#define MAX_CHARS 1000

int main() {
    char text[MAX_CHARS];

    printf("Enter some text (less than %d chars):\n", MAX_CHARS);
    fgets(text, MAX_CHARS, stdin);

    printf("\nProcessing text...\n");

    // Reverse the text
    printf("\nReversed text:\n");
    for (int i = strlen(text) - 1; i >= 0; i--) {
        printf("%c", text[i]);
    }

    // Count the number of words
    int count = 1;
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == ' ') {
            count++;
        }
    }
    printf("\n\nNumber of words: %d\n", count);

    // Convert the text to all uppercase
    printf("\nUppercase text:\n");
    for (int i = 0; i < strlen(text); i++) {
        printf("%c", toupper(text[i]));
    }

    // Replace all vowels with '*'
    printf("\n\nText with vowels replaced:\n");
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u') {
            printf("*");
        }
        else {
            printf("%c", text[i]);
        }
    }

    // Encrypt the text
    printf("\n\nEncrypted text:\n");
    for (int i = 0; i < strlen(text); i++) {
        printf("%c", text[i] + 3);
    }

    // Decrypt the text
    printf("\n\nDecrypted text:\n");
    for (int i = 0; i < strlen(text); i++) {
        printf("%c", text[i] - 3);
    }

    printf("\n\nDone processing text.");

    return 0;
}