//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define KEY "SECRETKEY"

void encrypt(char *message);

int main()
{
    char message[100];  /* the message to be encrypted */
    
    printf("Enter the message to be encrypted: ");
    fgets(message, sizeof(message), stdin);  /* read the message from user */
    
    encrypt(message);  /* encrypt the message */
    
    printf("Encrypted message: %s", message);  /* print the encrypted message */
    
    return 0;
}

/* Function to encrypt the message */
void encrypt(char *message)
{
    int i, j;
    char key[strlen(KEY)];
    strcpy(key, KEY);  /* copy the key to a temporary variable */
    
    for(i = 0, j = 0; i < strlen(message); ++i, ++j)
    {
        if(j == strlen(key))  /* if key is shorter than the message, start from beginning of key */
            j = 0;
        
        message[i] ^= key[j];  /* XOR the i-th character of the message with the j-th character of the key */
    }
}