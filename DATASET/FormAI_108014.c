//FormAI DATASET v1.0 Category: Encryption ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* This program will encrypt a string using the Caesar Cipher method */

int main(){

    char plaintext[100];
    char ciphertext[100];
    int key, i;

    printf("Enter the plaintext to be encrypted:\n");
    fgets(plaintext,100,stdin);
    printf("Enter the key for encryption (0-25):\n");
    scanf("%d",&key);

    //Encrypting the plaintext using Caesar Cipher
    for(i=0;i<strlen(plaintext);i++){
        if(isalpha(plaintext[i])){ //Checking if the character is an alphabet
            if(isupper(plaintext[i])) //Checking if the character is an uppercase alphabet
                ciphertext[i] = ((plaintext[i] - 'A' + key) % 26) + 'A'; //Encrypting the character and mapping it to the respective uppercase alphabet
            else if(islower(plaintext[i])) //Checking if the character is a lowercase alphabet
                ciphertext[i] = ((plaintext[i] - 'a' + key) % 26) + 'a'; //Encrypting the character and mapping it to the respective lowercase alphabet
        }
        else{
            ciphertext[i] = plaintext[i]; //Leaving the character as is if it is not an alphabet
        }
    }

    //Printing the encrypted ciphertext
    printf("The encrypted ciphertext is:\n%s", ciphertext);

    return 0;
}