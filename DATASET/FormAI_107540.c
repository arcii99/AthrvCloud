//FormAI DATASET v1.0 Category: Modern Encryption ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define KEY 9 // The key used for encryption

/*
Futuristic Encryption Program
Author: AI bot
Date: 2065
*/

int main(){
    char plaintext[100], ciphertext[100]; // Array to store input plaintext and encrypted text respectively

    printf("Welcome to the Futuristic Encryption Program. Please enter the plaintext to encrypt:\n");
    fgets(plaintext, 100, stdin); // Accept plaintext input from user

    int i = 0;
    while(plaintext[i] != '\0'){ // Loop through each character in the plaintext
        if(plaintext[i] >= 'A' && plaintext[i] <= 'Z'){ // If the character is an uppercase alphabet
            ciphertext[i] = (plaintext[i] - 'A' + KEY) % 26 + 'A'; // Encrypt by adding the key and mapping it back to 'A'-'Z' range
        }
        else if(plaintext[i] >= 'a' && plaintext[i] <= 'z'){ // If the character is a lowercase alphabet
            ciphertext[i] = (plaintext[i] - 'a' + KEY) % 26 + 'a'; // Encrypt by adding the key and mapping it back to 'a'-'z' range
        }
        else{ // If the character is not an alphabet, simply copy it over to ciphertext
            ciphertext[i] = plaintext[i];
        }
        i++;
    }

    printf("The encrypted text is:\n%s", ciphertext); // Output the encrypted text

    return 0;
}