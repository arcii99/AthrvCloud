//FormAI DATASET v1.0 Category: Encryption ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void shift_left(char* text, int key) {
    int i;
    for (i = 0; text[i] != '\0'; ++i) {
        text[i] = (text[i] - 'a' - key + 26) % 26 + 'a';
    }
}

void shift_right(char* text, int key) {
    int i;
    for (i = 0; text[i] != '\0'; ++i) {
        text[i] = (text[i] - 'a' + key) % 26 + 'a';
    }
}

void encrypt(char* text, int key) {
    shift_left(text, key);
    shift_right(text, key);
}

int main() {
    char message[1000];
    int key;

    printf("Enter message to encrypt: ");
    fgets(message, 1000, stdin);
    message[strcspn(message, "\n")] = 0;
    printf("Enter encryption key: ");
    scanf("%d", &key);

    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    return 0;
}