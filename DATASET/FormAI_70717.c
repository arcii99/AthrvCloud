//FormAI DATASET v1.0 Category: modern Encryption ; Style: cheerful
#include <stdio.h>
#include <string.h>

// Function to perform encryption
void encrypt(char message[], int key)
{
    int i;
    for(i=0; i<strlen(message); i++)
    {
        // For uppercase letters
        if(message[i]>='A' && message[i]<='Z')
        {
            message[i] = (char)(((int)message[i] + key - 65) % 26 + 65);
        }
        // For lowercase letters
        else if(message[i]>='a' && message[i]<='z')
        {
            message[i] = (char)(((int)message[i] + key - 97) % 26 + 97);
        }
    }
}

int main()
{
    char message[100]; // The message to be encrypted
    int key; // The key for encryption

    printf("Welcome to the cheerful encryption program!\n");
    printf("Enter the message you want to encrypt: ");
    fgets(message, 100, stdin); // Read message from user
    printf("Enter the key: ");
    scanf("%d", &key); // Read key from user

    // Perform encryption
    encrypt(message, key);

    printf("Your encrypted message is: %s\n", message); // Display encrypted message

    return 0;
}