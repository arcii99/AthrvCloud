//FormAI DATASET v1.0 Category: Modern Encryption ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define encryption key
#define KEY "randomkey"

void encrypt(char *input, char *output){
    int i, j = 0, len = strlen(KEY);
    for(i = 0; input[i] != '\0'; i++){
        output[i] = input[i] ^ KEY[j];
        j = (j + 1) % len;
    }
    output[i] = '\0';
}

void decrypt(char *input, char *output) {
    int i, j = 0, len = strlen(KEY);
    for (i = 0; input[i] != '\0'; i++) {
        output[i] = input[i] ^ KEY[j];
        j = (j + 1) % len;
    }
    output[i] = '\0';
}

int main(){
    char input[100], output[100], decrypted[100];
    printf("Enter message to encrypt: ");
    scanf("%s", input);

    encrypt(input, output);
    printf("Encrypted message: %s\n", output);

    decrypt(output, decrypted);
    printf("Decrypted message: %s\n", decrypted);

    return 0;
}