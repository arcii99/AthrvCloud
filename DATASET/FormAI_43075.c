//FormAI DATASET v1.0 Category: Encryption ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt(char *plaintext, int key){
    int len = strlen(plaintext);
    char *ciphertext = (char*) malloc(sizeof(char) * (len + 1));

    for(int i = 0; i < len; i++){
        if(plaintext[i] > 64 && plaintext[i] < 91){
            ciphertext[i] = ((plaintext[i] + key - 65) % 26) + 65;
        }else if(plaintext[i] > 96 && plaintext[i] < 123){
            ciphertext[i] = ((plaintext[i] + key - 97) % 26) + 97;
        }else{
            ciphertext[i] = plaintext[i];
        }
    }

    ciphertext[len] = '\0';
    return ciphertext;
}

void main(){
    char str[100];
    int key, len;
    char* cipher;

    printf("Enter the string to encrypt: ");
    scanf("%[^\n]s", str);

    printf("Enter the key for encryption: ");
    scanf("%d", &key);

    cipher = encrypt(str, key);

    printf("\nPlaintext: %s", str);
    printf("\nCiphertext: %s\n", cipher);

    free(cipher);
}