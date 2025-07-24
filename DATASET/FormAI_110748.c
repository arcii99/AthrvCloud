//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char message[100];
    printf("Enter your secret message: ");
    scanf("%[^\n]%*c", message);
    
    int key = strlen(message); // using message length as encryption key
    
    // encrypting the message
    for(int i = 0; i < strlen(message); i++)
    {
        message[i] = message[i] + key;
    }
    
    printf("Your encrypted message is: %s\n", message);
    
    // decrypting the message
    for(int i = 0; i < strlen(message); i++)
    {
        message[i] = message[i] - key;
    }
    
    printf("Your decrypted message is: %s\n", message);
    
    return 0;
}