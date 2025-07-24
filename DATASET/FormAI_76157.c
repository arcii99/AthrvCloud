//FormAI DATASET v1.0 Category: Modern Encryption ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define KEY 5

char* encrypt(char* message, int key) {
    int len = strlen(message);
    char* result = (char*) malloc((len + 1) * sizeof(char));

    for (int i = 0; message[i] != '\0'; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            result[i] = ((message[i] - 'a' + key) % 26) + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            result[i] = ((message[i] - 'A' + key) % 26) + 'A';
        } else {
            result[i] = message[i];
        }
    }

    result[len] = '\0';
    return result;
}

int main() {
    char message[MAX_SIZE], ch;
    int i = 0;

    printf("Enter a message to encrypt: ");
    while ((ch = getchar()) != '\n' && i < MAX_SIZE) {
        message[i++] = ch;
    }
    message[i] = '\0';

    char* encrypted = encrypt(message, KEY);
    printf("Encrypted Message: %s\n", encrypted);

    free(encrypted);
    return 0;
}