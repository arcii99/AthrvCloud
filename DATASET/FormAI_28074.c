//FormAI DATASET v1.0 Category: Modern Encryption ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

void encrypt(char str[], int key) {
    int n = strlen(str);
    for (int i = 0; i < n; i++) {
        if (str[i] != ' ') {
            str[i] = ((str[i] - 'a') + key) % 26 + 'a';
        }
    }
}

void decrypt(char str[], int key) {
    int n = strlen(str);
    for (int i = 0; i < n; i++) {
        if (str[i] != ' ') {
            str[i] = ((str[i] - 'a') - key + 26) % 26 + 'a';
        }
    }
}

int main() {
    char message[100];
    int key;

    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);
    printf("Enter key: ");
    scanf("%d", &key);

    printf("\nOriginal message: %s", message);

    encrypt(message, key);
    printf("Encrypted message: %s", message);

    decrypt(message, key);
    printf("Decrypted message: %s", message);

    return 0;
}