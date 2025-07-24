//FormAI DATASET v1.0 Category: Encryption ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    printf("Enter the string you want to encrypt: ");
    char input[100];
    scanf("%s", input);

    // Key used for encryption
    char key[5] = "abcd";

    // Length of input and key
    int input_len = strlen(input);
    int key_len = strlen(key);

    // Creating a new char array to store encrypted string
    char encrypted_string[input_len + 1];
    memset(encrypted_string, 0, input_len + 1);

    // Encrypting the string
    int i, j;
    for(i = 0, j = 0; i < input_len; ++i, ++j) {
        if(j == key_len)
            j = 0;
        encrypted_string[i] = ((input[i] + key[j]) % 26) + 'A';
    }

    // Printing the encrypted string
    printf("Encrypted String: %s\n", encrypted_string);

    // Creating a new char array to store decrypted string
    char decrypted_string[input_len + 1];
    memset(decrypted_string, 0, input_len + 1);

    // Decrypting the string
    for(i = 0, j = 0; i < input_len; ++i, ++j) {
        if(j == key_len)
            j = 0;
        decrypted_string[i] = (((encrypted_string[i] - key[j]) + 26) % 26) + 'A';
    }

    // Printing the decrypted string
    printf("Decrypted String: %s\n", decrypted_string);

    return 0;
}