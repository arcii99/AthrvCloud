//FormAI DATASET v1.0 Category: Encryption ; Style: curious
#include <stdio.h>
#include <string.h>

char* encrypt(char* text, int key) {
    int i;
    char* result = malloc(strlen(text) * sizeof(char));

    for(i = 0; i < strlen(text); i++) {
        char letter = text[i];

        if(letter >= 'A' && letter <= 'Z') {
            letter = ((letter - 'A') + key) % 26 + 'A';
        } else if(letter >= 'a' && letter <= 'z') {
            letter = ((letter - 'a') + key) % 26 + 'a';
        }

        result[i] = letter;
    }

    return result;
}

int main() {
    char text[] = "Hello, World!";
    int key = 5;

    char* encrypted = encrypt(text, key);

    printf("Original text: %s\n", text);
    printf("Encrypted text: %s\n", encrypted);

    free(encrypted);

    return 0;
}