//FormAI DATASET v1.0 Category: Modern Encryption ; Style: recursive
#include <stdio.h>
#include <string.h>

/* Recursive function to encrypt the message */
void encryptMessage(char* message, int key)
{
    int i, asciiValue;
    char encryptedMessage[100];
    
    /* Encrypt each character of the message */
    for(i=0; i<strlen(message); i++)
    {
        /* Convert character to ASCII value */
        asciiValue = (int)message[i];
        
        /* Shift the ASCII value by the key */
        asciiValue = (asciiValue + key) % 256;
        
        /* Convert the ASCII value back to character */
        encryptedMessage[i] = (char)asciiValue;
    }
    
    /* Null terminate the encrypted message */
    encryptedMessage[i] = '\0';
    
    /* Print the encrypted message */
    printf("Encrypted message: %s\n", encryptedMessage);
    
    /* Call the decrypt function */
    decryptMessage(encryptedMessage, key);
}

/* Recursive function to decrypt the message */
void decryptMessage(char* message, int key)
{
    int i, asciiValue;
    char decryptedMessage[100];
    
    /* Decrypt each character of the message */
    for(i=0; i<strlen(message); i++)
    {
        /* Convert character to ASCII value */
        asciiValue = (int)message[i];
        
        /* Shift the ASCII value by the key (in reverse direction) */
        asciiValue = (asciiValue - key + 256) % 256;
        
        /* Convert the ASCII value back to character */
        decryptedMessage[i] = (char)asciiValue;
    }
    
    /* Null terminate the decrypted message */
    decryptedMessage[i] = '\0';
    
    /* Print the decrypted message */
    printf("Decrypted message: %s\n", decryptedMessage);
    
    /* Call the encrypt function with the decrypted message */
    encryptMessage(decryptedMessage, key);
}

int main()
{
    char message[100];
    int key;
    
    /* Get the message to encrypt from the user */
    printf("Enter the message to encrypt: ");
    fgets(message, 100, stdin);
    
    /* Get the key from the user */
    printf("Enter the encryption key: ");
    scanf("%d", &key);
    
    /* Call the encrypt function */
    encryptMessage(message, key);
    
    return 0;
}