//FormAI DATASET v1.0 Category: Encryption ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "FUTURE"

void encrypt(char *str) {
    int keyLen = strlen(KEY), i;
    int strLen = strlen(str);

    for(i = 0; i < strLen; i++) {
        str[i] = str[i] ^ KEY[i % keyLen];
    }
}

void decrypt(char *str) {
    int keyLen = strlen(KEY), i;
    int strLen = strlen(str);

    for(i = 0; i < strLen; i++) {
        str[i] = str[i] ^ KEY[i % keyLen];
    }
}

int main() {
    char original[100] = "Hello, world!";
    char encrypted[100];
    char decrypted[100];

    printf("Original message: %s\n", original);

    encrypt(original);
    strcpy(encrypted, original);
    
    printf("Encrypted message: %s\n", encrypted);

    decrypt(encrypted);
    strcpy(decrypted, encrypted);

    printf("Decrypted message: %s\n", decrypted);

    return 0;
}