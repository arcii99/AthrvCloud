//FormAI DATASET v1.0 Category: Modern Encryption ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* encrypt(char* message, int key);

int main() {
    char message[1000];
    int key;
    printf("Enter the message to encrypt: ");
    fgets(message, 1000, stdin);
    printf("Enter the encryption key (number between 1 and 26): ");
    scanf("%d", &key);

    char* encrypted = encrypt(message, key);
    printf("Encrypted message: %s", encrypted);
    free(encrypted);

    return 0;
}

char* encrypt(char* message, int key) {
    char* result = (char*) malloc(strlen(message) + 1);
    for (int i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                result[i] = ((message[i] - 'A' + key) % 26) + 'A';
            } else {
                result[i] = ((message[i] - 'a' + key) % 26) + 'a';
            }
        } else {
            result[i] = message[i]; // non-alphabetic characters are copied over unchanged
        }
    }

    result[strlen(message)] = '\0'; // add null terminator
    return result;
}