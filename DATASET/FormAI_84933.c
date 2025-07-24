//FormAI DATASET v1.0 Category: Encryption ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to encrypt the given string using Caesar Cipher
void encrypt(char *str, int key)
{
    int len = strlen(str);
    
    // Apply Caesar Cipher to each character in the string
    for(int i=0; i<len; i++) {
        if(str[i] >= 'a' && str[i] <= 'z')
            str[i] = (str[i] - 'a' + key) % 26 + 'a';
        else if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] = (str[i] - 'A' + key) % 26 + 'A';
    }
}

// Function to generate a random key for Caesar Cipher
int generate_key()
{
    srand(time(NULL));
    return rand() % 26;  // Generate a random number between 0 and 25
}

int main() 
{
    char message[100];
    
    // Read the message from user
    printf("Enter your message: ");
    fgets(message, 100, stdin);
    
    // Generate a random key
    int key = generate_key();
    printf("Your encryption key is %d\n", key);
    
    // Encrypt the message using the key
    encrypt(message, key);
    
    // Display the encrypted message
    printf("Your encrypted message is: %s", message);
    
    return 0;
}