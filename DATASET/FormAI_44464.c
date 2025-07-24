//FormAI DATASET v1.0 Category: Encryption ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *input, char *key, char *output) {
    int i, j = 0;
    int input_len = strlen(input);
    int key_len = strlen(key);
    
    for(i = 0; i < input_len; i++) {
        output[i] = input[i] ^ key[j];
        j++;
        if (j == key_len) {
            j = 0;
        }
    }
    output[i] = '\0';
}

int main() {
    char input[100], key[100], output[100];
    printf("Enter message to encrypt: ");
    scanf("%s", input);
    printf("Enter encryption key: ");
    scanf("%s", key);
    encrypt(input, key, output);
    printf("Encrypted message is: %s\n", output);
    return 0;
}