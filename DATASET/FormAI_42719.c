//FormAI DATASET v1.0 Category: Encryption ; Style: optimized
#include <stdio.h>
#include <string.h>

#define KEY 3 // Define encryption key (can be any number)

void encrypt(char* str) // Function to encrypt a string
{
    int len = strlen(str);
    for(int i = 0; i < len; i++)
    {
        if(str[i] != ' ') // Ignore spaces
        {
            str[i] = ((str[i] - 'a') + KEY) % 26 + 'a'; // Shift character by key value
        }
    }
}

int main()
{
    char message[100]; // Define character array to store message
    printf("Enter message to encrypt:\n");
    fgets(message, sizeof(message), stdin); // Read input from user

    encrypt(message); // Encrypt the message

    printf("Encrypted message: %s", message); // Display encrypted message

    return 0;
}