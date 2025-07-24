//FormAI DATASET v1.0 Category: modern Encryption ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* message, int key){
    int len = strlen(message);
    char* cipher = malloc(len * sizeof(char)); // allocate memory for the cipher
    for(int i=0; i<len; i++){
        cipher[i] = ((message[i] - 32 + key) % 95) + 32; // shift the ASCII value by the key and restrict to printable ASCII range
    }
    cipher[len] = '\0'; // add null character at the end of cipher
    strcpy(message, cipher); // copy the cipher to the original message string
    free(cipher); // free the allocated memory
}

void decrypt(char* cipher, int key){
    int len = strlen(cipher);
    char* message = malloc(len * sizeof(char)); // allocate memory for the original message
    for(int i=0; i<len; i++){
        message[i] = ((cipher[i] - 32 - key + 95) % 95) + 32; // reverse the encryption process to get the original message
    }
    message[len] = '\0'; // add null character at the end of original message
    strcpy(cipher, message); // copy the original message to the cipher string
    free(message); // free the allocated memory
}

int main(){
    char message[100];
    int key;
    printf("Enter the message to encrypt: ");
    scanf("%[^\n]%*c", message); // read the input message including spaces
    printf("Enter the encryption key (1-94): ");
    scanf("%d", &key);
    encrypt(message, key); // encrypt the message
    printf("Encrypted message: %s\n", message);
    decrypt(message, key); // decrypt the message
    printf("Decrypted message: %s\n", message);
    return 0;
}