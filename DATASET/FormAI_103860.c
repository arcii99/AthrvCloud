//FormAI DATASET v1.0 Category: Modern Encryption ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Encryption helper function
char* encrypt(char* message, int key) {
    int len = strlen(message);
    char* result = (char*) malloc(len * sizeof(char));

    for(int i = 0; i < len; i++) {
        result[i] = (message[i] + key) % 128;
    }

    return result;
}

int main() {
    char message[100];
    int key;

    printf("Enter message to encrypt: ");
    scanf("%[^\n]s", message);

    printf("Enter encryption key: ");
    scanf("%d", &key);

    char* encrypted_message = encrypt(message, key);

    printf("\nEncrypted message: %s\n", encrypted_message);

    free(encrypted_message);
    
    return 0;
}