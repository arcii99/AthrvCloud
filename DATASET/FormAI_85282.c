//FormAI DATASET v1.0 Category: Modern Encryption ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* This program takes an input string from the user and encrypts it using a modified Caesar cipher algorithm
*/

int main() {
    
    // Prompt user to enter a message to encrypt
    printf("Welcome to the Modern Encryption Program!\n");
    printf("Please enter a message to encrypt: ");
    
    char message[1000];
    fgets(message, 1000, stdin);
    
    // Prompt user to enter an encryption key
    printf("Please enter an encryption key: ");
    
    int key;
    scanf("%d", &key);
    getchar();
    
    // Encrypt the message
    
    int i = 0;
    char encrypted[1000];
    
    while(message[i] != '\0') {
        if(message[i] >= 'a' && message[i] <= 'z'){
            encrypted[i] = (message[i] + key - 'a') % 26 + 'a';
        }
        else if(message[i] >= 'A' && message[i] <= 'Z'){
            encrypted[i] = (message[i] + key - 'A') % 26 + 'A';
        }
        else{
            encrypted[i] = message[i];
        }
        i++;
    }
    
    encrypted[i] = '\0';
    
    // Display the encrypted message
    printf("The encrypted message is: %s\n", encrypted);
    
    return 0;
}