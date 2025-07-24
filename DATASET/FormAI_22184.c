//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

/* Ken Thompson-style Modern Encryption Example */

void encrypt(char* str, int key) {
    int len = strlen(str);
    for(int i=0; i<len; i++) {
        str[i] ^= key;
        key += 2; // Increment key by 2
    }
}

void decrypt(char* str, int key) {
    encrypt(str, key);
}

int main() {
    char message[100];
    int key;

    printf("Enter message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter encryption key: ");
    scanf("%d", &key);

    encrypt(message, key);
    printf("\nEncrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}