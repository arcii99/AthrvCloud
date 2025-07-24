//FormAI DATASET v1.0 Category: Encryption ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt(char* message, int key) {
    int len = strlen(message);
    char* ciphertext = malloc(len+1);
    memset(ciphertext, 0, len+1);
    for(int i=0; i<len; i++) {
        ciphertext[i] = message[i] + key;  // add key to each character
    }
    return ciphertext;
}

int main() {
    printf("Enter the message to encrypt:\n");
    char message[100];
    fgets(message, 100, stdin);  // read input from user
    int key;
    printf("Enter the encryption key:\n");
    scanf("%d", &key);
    char* ciphertext = encrypt(message, key);  // call encrypt function
    printf("Encrypted message:\n%s", ciphertext);
    free(ciphertext);  // free allocated memory
    return 0;
}