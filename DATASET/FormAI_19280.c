//FormAI DATASET v1.0 Category: Modern Encryption ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Encryption function */
void encrypt(char *str, int key) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = (str[i] - 'a' + key) % 26 + 'a';
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = (str[i] - 'A' + key) % 26 + 'A';
        }
    }
}

/* Decryption function */
void decrypt(char *str, int key) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = (str[i] - 'a' - key + 26) % 26 + 'a';
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = (str[i] - 'A' - key + 26) % 26 + 'A';
        }
    }
}

int main() {
    char str[1000];
    int key;

    printf("Enter a string to encrypt: ");
    fgets(str, 1000, stdin);
    str[strcspn(str, "\n")] = 0; /* remove newline from fgets */

    printf("Enter encryption key: ");
    scanf("%d", &key);

    /* Encrypt the string */
    encrypt(str, key);
    printf("Encrypted string: %s\n", str);

    /* Decrypt the string */
    decrypt(str, key);
    printf("Decrypted string: %s\n", str);

    return 0;
}