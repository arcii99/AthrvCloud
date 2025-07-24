//FormAI DATASET v1.0 Category: Modern Encryption ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to encrypt the message using the Modern Encryption technique
void encrypt(char message[], int key)
{
    int i;
    char encrypted_message[100]; //initialize the encrypted message variable
    
    for(i=0; i<strlen(message); i++)
    {
        encrypted_message[i] = message[i]+key; //increment the ASCII value of each character by the key
    }
    encrypted_message[i] = '\0'; //terminate the encrypted message
    
    printf("Encrypted message: %s", encrypted_message);
}

int main()
{
    char message[100]; //initialize the message variable
    int key;
    
    printf("Enter the message to be encrypted: ");
    scanf("%s", message);
    
    printf("Enter the encryption key: ");
    scanf("%d", &key);
    
    encrypt(message, key); //call the encrypt function to encrypt the message
    
    return 0;
}