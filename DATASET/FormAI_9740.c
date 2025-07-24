//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: immersive
#include<stdio.h>
#include<stdlib.h>

// This program demonstrates how to perform cryptographic operations in the C language

int main() {

    int key = 5; // the key that will be used for encryption and decryption
    char message[100];

    printf("Welcome to the Cryptography Implementation program!\n");
    printf("Enter the message you want to encrypt: ");
    fgets(message, sizeof(message), stdin); // read the message from the user

    // encryption starts here
    int i;
    for (i = 0; message[i] != '\n'; i++) {
        int temp = message[i];
        if (temp >= 'a' && temp <= 'z') {
            temp = temp + key;
            if (temp > 'z') {
                temp = temp - 'z' + 'a' - 1;
            }
            message[i] = temp;
        }
        else if (temp >= 'A' && temp <= 'Z') {
            temp = temp + key;
            if (temp > 'Z') {
                temp = temp - 'Z' + 'A' - 1;
            }
            message[i] = temp;
        }
    }

    printf("Encrypted message: %s", message);
    
    // decryption starts here
    for (i = 0; message[i] != '\n'; i++) {
        int temp = message[i];
        if (temp >= 'a' && temp <= 'z') {
            temp = temp - key;
            if (temp < 'a') {
                temp = temp + 'z' - 'a' + 1;
            }
            message[i] = temp;
        }
        else if (temp >= 'A' && temp <= 'Z') {
            temp = temp - key;
            if (temp < 'A') {
                temp = temp + 'Z' - 'A' + 1;
            }
            message[i] = temp;
        }
    }

    printf("Decrypted message: %s", message);
    
    return 0;
}