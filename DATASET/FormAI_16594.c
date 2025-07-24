//FormAI DATASET v1.0 Category: modern Encryption ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to perform the encryption */
void encrypt(char data[], char key[]) {
    int keyLength = strlen(key);
    int i;

    for(i=0;data[i]!='\0';i++) {
        /* performing XOR operation to the data string */
        data[i]= data[i] ^ key[i % keyLength];
    }
}

int main() {
    char message[100]; /* message to be encrypted */
    char key[100]; /* encryption key */

    printf("Enter your message: ");
    fgets(message, 100, stdin); /* reading the input message from user */
    printf("Enter the encryption key: ");
    fgets(key, 100, stdin); /* reading the encryption key from user */

    /* performing encryption */
    encrypt(message, key);

    printf("\nEncrypted message: ");
    fputs(message, stdout); /* prints the encrypted message string */
    
    return 0;
}