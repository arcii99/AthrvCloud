//FormAI DATASET v1.0 Category: Encryption ; Style: introspective
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Function to display the encryption key
void display_key(int key)
{
    printf("The encryption key is: %d\n", key);
}

int main()
{
    int key = 5; // Set the encryption key to 5

    display_key(key); // Call the display_key function to display the key

    char message[100]; // Declare a character array to store the message
    printf("Enter the message to be encrypted: ");
    fgets(message, 100, stdin); // Read the message from the user

    // Loop through each character in the message and encrypt it
    for(int i=0; i<strlen(message); i++)
    {
        // Check if the current character is a letter
        if(isalpha(message[i]))
        {
            // Check if the current character is upper case
            if(isupper(message[i]))
            {
                message[i] = (((message[i] - 65) + key) % 26) + 65; // Encrypt the character
            }
            else
            {
                message[i] = (((message[i] - 97) + key) % 26) + 97; // Encrypt the character
            }
        }
    }

    printf("The encrypted message is: %s\n", message); // Display the encrypted message

    return 0;
}