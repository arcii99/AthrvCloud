//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 1000

char* encrypt(char input[MAX_LEN], int key) {
    char* output = (char*)malloc(sizeof(char) * MAX_LEN);

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            output[i] = ((input[i] - 'a' + key) % 26) + 'a'; 
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            output[i] = ((input[i] - 'A' + key) % 26) + 'A';
        } else {
            output[i] = input[i];
        }
    }

    output[MAX_LEN - 1] = '\0';

    return output;
}

int main() {
    char input[MAX_LEN]; 
    int key;

    printf("Enter the text to be encrypted: ");
    fgets(input, MAX_LEN, stdin);

    printf("Enter the encryption key: ");
    scanf("%d", &key);

    printf("\n");

    char* encrypted_output = encrypt(input, key);

    printf("Encrypted text: %s", encrypted_output);

    free(encrypted_output);

    return 0;
}