//FormAI DATASET v1.0 Category: Modern Encryption ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt(char* msg, char* key);

int main() {
    char msg[100], key[100], *encrypted_msg;

    /* Taking the input message and key from the user */
    printf("Enter the message to be encrypted: ");
    gets(msg);

    printf("Enter the key to be used for encryption: ");
    gets(key);

    /* Encrypting the message using the given key*/
    encrypted_msg = encrypt(msg, key);

    /* Displaying the encrypted message */
    printf("Encrypted message: %s", encrypted_msg);

    /* Freeing the memory allocated to the encrypted message*/
    free(encrypted_msg);

    return 0;
}

char* encrypt(char* msg, char* key) {
    int len_msg = strlen(msg);
    int len_key = strlen(key);
    char* encrypted_msg = (char*) malloc((len_msg + 1) * sizeof(char));

    /* Encrypting the message character by character */
    for(int i=0; i<len_msg; i++){
        encrypted_msg[i] = msg[i] ^ key[i % len_key];
    }

    /* Adding the null character at the end */
    encrypted_msg[len_msg] = '\0';

    return encrypted_msg;
}