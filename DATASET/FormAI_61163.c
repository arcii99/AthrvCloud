//FormAI DATASET v1.0 Category: Modern Encryption ; Style: sophisticated
#include <stdio.h>
#include <string.h>

void print(char msg[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%c", msg[i]);
    }
}

int main() {
    char message[100], key[100], encrypted[100], decrypted[100];
    int len, keylen, i, j = 0;

    printf("Enter message to encrypt: ");
    scanf("%[^\n]s", message);
    len = strlen(message);

    printf("Enter encryption key: ");
    scanf(" %[^\n]s", key);
    keylen = strlen(key);

    // encryption
    for (i = 0; i < len; i++) {
        encrypted[i] = message[i] ^ key[j];
        j++;
        if (j >= keylen) {
            j = 0;
        }
    }
    printf("Encrypted message: ");
    print(encrypted, len);

    // decryption
    j = 0;
    for (i = 0; i < len; i++) {
        decrypted[i] = encrypted[i] ^ key[j];
        j++;
        if (j >= keylen) {
            j = 0;
        }
    }
    printf("Decrypted message: ");
    print(decrypted, len);

    return 0;
}