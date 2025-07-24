//FormAI DATASET v1.0 Category: Encryption ; Style: synchronous
#include <stdio.h>
#include <string.h>

void encrypt(char *input, char *key, char *output){
    int i, j = 0, key_length = strlen(key);

    for(i = 0; i < strlen(input); i++){
        output[i] = input[i] ^ key[j];
        j = (j + 1) % key_length;
    }

    output[i] = '\0';
}

int main(){
    char input[100], key[100], output[100];

    printf("Enter the input text to be encrypted: ");
    fgets(input, 100, stdin);

    printf("Enter the encryption key: ");
    fgets(key, 100, stdin);

    encrypt(input, key, output);

    printf("The encrypted text is: %s\n", output);

    return 0;
}