//FormAI DATASET v1.0 Category: Modern Encryption ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LIMIT 10000 //maximum number of characters in user input

char* encrypt(char* message, int key)
{
    char* cipherText = (char*)malloc(sizeof(char) * strlen(message)); //allocate memory for cipherText
    
    for(int i=0; i<strlen(message); i++)
    {
        if(message[i] >= 'a' && message[i] <= 'z')
        {
            cipherText[i] = ((message[i] - 'a') + key) % 26 + 'a'; //shift by 'key'
        }
        else if(message[i] >= 'A' && message[i] <= 'Z')
        {
            cipherText[i] = ((message[i] - 'A') + key) % 26 + 'A'; //shift by 'key'
        }
        else
        {
            cipherText[i] = message[i];
        }
    }
    return cipherText; //return encrypted text
}

int main()
{
    char message[MAX_LIMIT]; //store user input in array
    int key;
    char* cipherText;
    
    printf("\nWelcome to the Modern Encryption Program\n");
    printf("\nPlease enter the message to encrypt (max %d characters):\n", MAX_LIMIT);
    scanf("%[^\n]s", message); //store user input in string format
    
    printf("\nPlease enter the key (an integer between 1 and 25):\n");
    scanf("%d", &key); //store user input in integer format
    
    cipherText = encrypt(message, key); //encrypt the message using key and store in cipherText
    
    printf("\nYour encrypted message is:\n%s\n", cipherText); //print encrypted message
    
    free(cipherText); //free memory allocated to cipherText
    
    return 0; //program execution completed successfully
}