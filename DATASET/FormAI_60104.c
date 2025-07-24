//FormAI DATASET v1.0 Category: Encryption ; Style: real-life
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* user-defined function for encryption */
char* encrypt(char *str, int key) {
    int i;
    char *cipher = (char*) malloc(strlen(str) + 1);
    for(i = 0; i < strlen(str); i++) {
        /* check if character is uppercase */
        if(isupper(str[i])) {
            cipher[i] = (((str[i] - 'A') + key) % 26) + 'A';
        } 
        /* check if character is lowercase */
        else if(islower(str[i])) {
            cipher[i] = (((str[i] - 'a') + key) % 26) + 'a';
        }
        /* character is not an alphabet, like a space or punctuation mark */
        else {
            cipher[i] = str[i];
        }
    }
    cipher[i] = '\0';
    return cipher; // return the encrypted string
}

int main() {
    char message[100], *cipher;
    int key;
    printf("Enter the message to encrypt: ");
    fgets(message, 100, stdin);
    printf("Enter the encryption key: ");
    scanf("%d", &key);
    /* call the encryption function and store the result in a variable */
    cipher = encrypt(message, key);
    printf("Encrypted message: %s\n", cipher);
    free(cipher); // deallocate the allocated memory
    return 0;
}