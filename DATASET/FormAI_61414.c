//FormAI DATASET v1.0 Category: Encryption ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the string using a futuristic encryption algorithm
void encrypt(char *input, char *key) {
    int len_input = strlen(input);
    int len_key = strlen(key);
    int i, j;

    // Generate a random key of the same length as input string
    char random_key[len_input + 1];
    for (i = 0; i < len_input; i++) {
        int index = rand() % len_key;
        random_key[i] = key[index];
    }
    random_key[len_input] = '\0';

    // XOR each character of input with corresponding character of random key
    for (i = 0, j = 0; i < len_input; i++, j++) {
        if (j == len_input) {
            j = 0;
        }
        input[i] = input[i] ^ random_key[j];
    }
}

int main() {
    char input[1000], key[1000];

    printf("Enter the string to encrypt: ");
    scanf("%[^\n]%*c", input);

    printf("Enter the key to encrypt the string with: ");
    scanf("%[^\n]%*c", key);
    
    encrypt(input, key);

    printf("\nEncrypted string: %s\n", input);

    return 0;
}