//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: lively
#include<stdio.h>

//Defining Unique Encryption Key
#define ENCRYPTION_KEY 13

//Function to Encrypt the Message
void encrypt(char *message) {
    char c;
    int i;
    for(i = 0; message[i] != '\0'; ++i) {
        c = message[i];
        if(c >= 'a' && c <= 'z') {
            c = c + ENCRYPTION_KEY;
            if(c > 'z') {
                c = c - 'z' + 'a' - 1;
            }
            message[i] = c;
        }
        else if(c >= 'A' && c <= 'Z') {
            c = c + ENCRYPTION_KEY;
            if(c > 'Z') {
                c = c - 'Z' + 'A' - 1;
            }
            message[i] = c;
        }
    }
    printf("Encrypted Message: %s\n", message);
}

//Function to Decrypt the Message
void decrypt(char *message) {
    char c;
    int i;
    for(i = 0; message[i] != '\0'; ++i) {
        c = message[i];
        if(c >= 'a' && c <= 'z') {
            c = c - ENCRYPTION_KEY;
            if(c < 'a') {
                c = c + 'z' - 'a' + 1;
            }
            message[i] = c;
        }
        else if(c >= 'A' && c <= 'Z') {
            c = c - ENCRYPTION_KEY;
            if(c < 'A') {
                c = c + 'Z' - 'A' + 1;
            }
            message[i] = c;
        }
    }
    printf("Decrypted Message: %s\n", message);
}

int main() {
    char message[100];

    //Taking Input from User
    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);
 
    //Encrypting the Message
    encrypt(message);

    //Decrypting the Message
    decrypt(message);
    
    return 0;
}