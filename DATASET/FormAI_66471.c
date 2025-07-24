//FormAI DATASET v1.0 Category: Encryption ; Style: peaceful
#include <stdio.h>
#include <string.h>

char* encrypt(char* message, char* key) {
    int length = strlen(message);
    char* encrypted = malloc(length * sizeof(char));

    for(int i = 0; i < length; i++) {
        int index = message[i] - 'a';
        encrypted[i] = key[index];
    }

    encrypted[length] = '\0';
    return encrypted;
}

int main() {
    char* message = "peaceful";
    char* key = "mnopqrstuvwxyza";

    char* encrypted = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted);

    free(encrypted);
    return 0;
}