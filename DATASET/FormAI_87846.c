//FormAI DATASET v1.0 Category: Encryption ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* input, char* output, char* key) {
    int i;
    int lkey = strlen(key);
    int llen = strlen(input);
    for (i = 0; i < llen; i++) {
        output[i] = input[i] ^ key[i % lkey];
    }
}

int main() {
    char input[100], output[100], key[100];
    printf("Enter the plaintext to be encrypted: ");
    fgets(input, 100, stdin);
    printf("Enter the encryption key: ");
    fgets(key, 100, stdin);

    int llen = strlen(input);
    if(llen > 0 && input[llen - 1] == '\n') {
        input[--llen] = '\0';
    }
    int lkey = strlen(key);
    if(lkey > 0 && key[lkey - 1] == '\n') {
        key[--lkey] = '\0';
    }

    encrypt(input, output, key);

    printf("\nEncrypted Message: ");
    for (int i = 0; i < strlen(input); i++) {
        printf("%d ", output[i]);
    }

    return 0;
}