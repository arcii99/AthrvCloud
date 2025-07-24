//FormAI DATASET v1.0 Category: Encryption ; Style: careful
#include<stdio.h>
#include<string.h>

int main()
{
    char message[100];
    int key;

    // Get message and key from user
    printf("Enter a message to encrypt: ");
    scanf("%s", message);
    printf("Enter a key for encryption: ");
    scanf("%d", &key);

    // Encrypt the message using Caesar Cipher technique
    int i;
    for(i = 0; i < strlen(message); i++)
    {
        char ch = message[i];
        if(ch >= 'a' && ch <= 'z')
        {
            ch = (ch + key - 'a') % 26 + 'a';
        }
        else if(ch >= 'A' && ch <= 'Z')
        {
            ch = (ch + key - 'A') % 26 + 'A';
        }
        message[i] = ch;
    }

    // Print the encrypted message
    printf("Encrypted message: %s", message);

    return 0;
}