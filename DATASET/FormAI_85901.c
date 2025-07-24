//FormAI DATASET v1.0 Category: Encryption ; Style: peaceful
#include<stdio.h>
#include<string.h>

int main()
{
    char message[100];
    int key, i;
    
    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);
    
    printf("Enter encryption key: ");
    scanf("%d", &key);
    
    //Encrypting the message
    for(i = 0; message[i] != '\0'; i++)
    {
        //If character is not an alphabet, skip it
        if(message[i] < 'a' || message [i] > 'z')
        {
            continue;
        }
        
        //Add key to the character
        message[i] = ((message[i] + key - 'a') % 26) + 'a';
    }
    
    printf("Encrypted message: %s", message);
    
    return 0;
}