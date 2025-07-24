//FormAI DATASET v1.0 Category: Encryption ; Style: careful
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// function to encrypt the input string
void encrypt(char* input, char* key) {
    int i, j = 0, len_key = strlen(key);
    for(i = 0; i < strlen(input); i++) {
        input[i] = input[i] ^ key[j];
        j = (j+1) % len_key;
    }
}

// function to decrypt the encrypted string
void decrypt(char* input, char* key) {
    encrypt(input, key); // decrypt and encrypt yields the original string
}

int main() {
    char input[100], key[100];
    printf("Enter the string to be encrypted: ");
    fgets(input, 100, stdin);
    printf("Enter the encryption key: ");
    fgets(key, 100, stdin);

    // remove the newline characters from input and key
    input[strcspn(input, "\n")] = 0;
    key[strcspn(key, "\n")] = 0;

    // encrypt the input string
    encrypt(input, key);

    printf("The encrypted string is: %s\n", input);

    // decrypt the encrypted string
    decrypt(input, key);

    printf("The decrypted string is: %s\n", input);

    return 0;
}