//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: unmistakable
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main() 
{ 
    // The message to be encrypted 
    char message[100]; 
    printf("Enter message to be encrypted: "); 
    scanf("%[^\n]", message); 
    
    // The key to be used for encryption
    int key = 3;
    
    int messageLength = 0;
    int i = 0;
    
    // Converting the message to integer array 
    while (message[i] != '\0') 
    { 
        messageLength++;
        i++;
    } 
    
    int messageInt[messageLength];
    
    for (i = 0; i < messageLength; i++)
    {
        messageInt[i] = (int)message[i];
    }
    
    // Encrypting the message using Caesar Cipher algorithm
    for (i = 0; i < messageLength; i++)
    {
        messageInt[i] = (messageInt[i] + key) % 256;
    }
    
    // Converting the message back to string
    char encryptedMessage[messageLength];
    
    for (i = 0; i < messageLength; i++)
    {
        encryptedMessage[i] = (char)messageInt[i];
    }
    
    printf("Encrypted Message: %s", encryptedMessage); 
    
    return 0;
}