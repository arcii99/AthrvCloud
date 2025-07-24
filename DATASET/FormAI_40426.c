//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256

void xor(char *str, char *key, int key_len, char *output) {
    int str_len = strlen(str);
    int i;
    for(i=0 ; i<str_len ; i++){
        output[i] = str[i] ^ key[i%key_len];
    }
    output[i] = '\0';
}

int main () {
    char plaintext[MAX_SIZE];
    char key[MAX_SIZE];
    char ciphertext[MAX_SIZE];

    printf("Enter the plaintext: ");
    scanf("%[^\n]%*c", plaintext);

    printf("Enter the key: ");
    scanf("%[^\n]%*c", key);

    int key_len = strlen(key);

    xor(plaintext, key, key_len, ciphertext);

    printf("\nCiphertext: %s\n", ciphertext);

    return 0;
}