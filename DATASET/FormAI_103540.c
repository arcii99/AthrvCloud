//FormAI DATASET v1.0 Category: modern Encryption ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

// Function to encrypt a message
void encryptMessage(char *message)
{
    // Count the frequency of each alphabet
    int frequency[26] = {0};
    for(int i = 0; message[i] != '\0'; i++)
    {
        if(message[i] >= 'a' && message[i] <= 'z')
        {
            frequency[message[i] - 'a']++;
        }
    }
    
    // Calculate the encryption key
    int key = 0;
    for(int i = 0; i < 26; i++)
    {
        if(frequency[i] > frequency[key])
        {
            key = i;
        }
    }
    key = (key + 3) % 26;
    
    // Encrypt the message
    for(int i = 0; message[i] != '\0'; i++)
    {
        if(message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = ((message[i] - 'a') + key) % 26 + 'a';
        }
    }
}

int main()
{
    char message[100];
    
    printf("Enter a message: ");
    scanf("%[^\n]", message);
    
    encryptMessage(message);
    printf("Encrypted message: %s\n", message);
    
    return 0;
}