//FormAI DATASET v1.0 Category: Encryption ; Style: irregular
//We will use a Caesar Cipher to encrypt a message in C programming language 
//This Caesar cipher takes each character from the plain text and shifts it forward by a certain number called the key

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h> //header file for character functions like isalpha(), islower() and toupper()


int main()
{
    char plainText[100]; //initialize string with 100 characters
    printf("Enter a message to encrypt: "); //message to be encrypted
    fgets(plainText, 100, stdin); //reads string with maximum number of characters as 100

    
    int key = 3; // shift key will be 3 i.e every character will be shifted by 3 indexes
    
    
    for(int i = 0; i < strlen(plainText); i++) // for loop to apply the Caesar cipher
    {
        if(isalpha(plainText[i]))//check if the input string has alphabets. Punctuation marks and digits don't need to be shifted 
        {
            if(islower(plainText[i]))
            {
                int letter = plainText[i] - 'a';// Code for small letters           
                letter = (letter + key) % 26;
                plainText[i] = letter + 'a';
            }
            else
            {
                int letter = plainText[i] - 'A';// Code for Capital letters
                letter = (letter + key) % 26;
                plainText[i] = letter + 'A';
            }
        }
        
    }
    printf("\nEncrypted message: %s", plainText); //prints encrypted message 
    return 0;
}