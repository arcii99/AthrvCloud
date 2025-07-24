//FormAI DATASET v1.0 Category: Encryption ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to perform encryption
char* encrypt(char* message, int key)
{
    int len = strlen(message), i;
    char *encryptedMsg = (char*)malloc((len+1) * sizeof(char)); //allocate memory for encrypted message
    
    for(i=0; i<len; i++)
    {
        if((message[i]>='a') && (message[i]<='z')) //encrypt lower case letters
        {
            encryptedMsg[i] = (((message[i] - 'a') + key) % 26) + 'a'; 
        }
        else if((message[i]>='A') && (message[i]<='Z')) //encrypt upper case letters
        {
            encryptedMsg[i] = (((message[i] - 'A') + key) % 26) + 'A'; 
        }
        else //keep other characters as it is
        {
            encryptedMsg[i] = message[i];
        }
    }
    
    encryptedMsg[i] = '\0'; //add null character to end of encrypted message
    return encryptedMsg;
}

int main()
{
    char message[100], *encryptedMsg;
    int key;
    
    printf("Enter the message to be encrypted: ");
    fgets(message, sizeof(message), stdin); //get input from user
    
    printf("Enter the key (0-25): ");
    scanf("%d", &key); //get input from user
    
    encryptedMsg = encrypt(message, key); //call encrypt function to encrypt the message
    
    printf("The encrypted message is: %s\n", encryptedMsg); //print the encrypted message
    
    free(encryptedMsg); //free the memory allocated for encrypted message
    return 0;
}