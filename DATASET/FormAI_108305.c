//FormAI DATASET v1.0 Category: Encryption ; Style: complex
#include<stdio.h>
#include<string.h>

// Declare the encryption key
const char key[] = "my secret key";

// Function to encrypt the data
void encrypt(char* data, int length)
{
    int key_length = strlen(key);
    int i, j;
    
    // Loop through the data
    for(i=0, j=0; i<length; i++, j++)
    {
        // Wrap around the key length
        if(j == key_length)
            j = 0;
        
        // XOR the data with the key
        data[i] = data[i] ^ key[j];
    }
}

// Function to decrypt the data
void decrypt(char* data, int length)
{
    encrypt(data, length);
}

int main()
{
    // Declare the data
    char data[100] = "Hello, World!";
    
    // Get the length of the data
    int length = strlen(data);
    
    // Encrypt the data
    encrypt(data, length);
    
    // Print the encrypted data
    printf("Encrypted Data: %s\n", data);
    
    // Decrypt the data
    decrypt(data, length);
    
    // Print the decrypted data
    printf("Decrypted Data: %s\n", data);
    
    return 0;
}