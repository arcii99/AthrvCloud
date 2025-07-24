//FormAI DATASET v1.0 Category: Modern Encryption ; Style: standalone
#include <stdio.h>
#include <string.h>

// Function to rotate characters of a string by a given key
char* rotate(char* str, int key)
{
    int i;
    char temp;
    int len = strlen(str);
    
    // Rotate each character by the given key
    for(i = 0; i < len; i++)
    {
        temp = str[i];
        str[i] = str[(i+key)%len];
        str[(i+key)%len] = temp;
    }
    
    return str;
}

int main()
{
    char message[100];
    int key;
    
    // Get the message and key from the user
    printf("Enter message to encrypt: ");
    scanf("%s", message);
    printf("Enter key for encryption (between 1 and 25): ");
    scanf("%d", &key);
    
    // Rotate the message by the key
    char* encrypted_message = rotate(message, key);
    
    // Display the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);
    
    // Rotate the encrypted message back to get the original message
    char* decrypted_message = rotate(encrypted_message, -key);
    
    // Display the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);
    
    return 0;
}