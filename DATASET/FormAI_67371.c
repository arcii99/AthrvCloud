//FormAI DATASET v1.0 Category: Encryption ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Grateful C Encryption Example Program
int main(){
    char phrase[100], key[100];
    int i, j, phraseLength, keyLength, newChar;

    //Greeting Message
    printf("Welcome to the Grateful Encryption Program!\n\n");

    //Get user's phrase and key input
    printf("Please enter the phrase you want to encrypt (max 100 characters):\n");
    gets(phrase);
    phraseLength = strlen(phrase);
    printf("\nPlease enter the key you want to use to encrypt the phrase (max 100 characters):\n");
    gets(key);
    keyLength = strlen(key);

    //Encrypt the phrase with the given key
    printf("\nEncrypting...\n");
    for(i=0; i<phraseLength; i++){
        j = i % keyLength;
        newChar = ((int)phrase[i] + (int)key[j]) % 128;
        phrase[i] = (char)newChar;
    }

    //Print the encrypted phrase
    printf("\nThe encrypted phrase is:\n%s\n", phrase);

    //Decrypt the phrase with the given key
    printf("Decrypting...\n");
    for(i=0; i<phraseLength; i++){
        j = i % keyLength;
        newChar = ((int)phrase[i] - (int)key[j] + 128) % 128;
        phrase[i] = (char)newChar;
    }

    //Print the decrypted phrase
    printf("\nThe decrypted phrase is:\n%s\n", phrase);
    printf("\nThank you for using the Grateful Encryption Program!");
    return 0;
}