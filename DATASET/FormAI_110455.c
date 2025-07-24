//FormAI DATASET v1.0 Category: Modern Encryption ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LEN 100

// Function to generate encryption key
void generate_key(int key[])
{
    // Initialize random number generator
    srand(time(NULL));

    // Generate random numbers between 1 and 26
    for(int i=0; i<26; i++)
    {
        key[i] = rand() % 26 + 1;
    }
}

// Function to encrypt message using key
void encrypt(char msg[], int key[])
{
    int len = strlen(msg);

    // Loop through message and apply key
    for(int i=0; i<len; i++)
    {
        if(msg[i] >= 'a' && msg[i] <= 'z')
        {
            msg[i] = (msg[i] - 'a' + key[msg[i]-'a']) % 26 + 'a';
        }
        else if(msg[i] >= 'A' && msg[i] <= 'Z')
        {
            msg[i] = (msg[i] - 'A' + key[msg[i]-'A']) % 26 + 'A';
        }
    }
}

// Function to decrypt message using key
void decrypt(char msg[], int key[])
{
    int len = strlen(msg);

    // Loop through message and apply key
    for(int i=0; i<len; i++)
    {
        if(msg[i] >= 'a' && msg[i] <= 'z')
        {
            msg[i] = (msg[i] - 'a' - key[msg[i]-'a'] + 26) % 26 + 'a';
        }
        else if(msg[i] >= 'A' && msg[i] <= 'Z')
        {
            msg[i] = (msg[i] - 'A' - key[msg[i]-'A'] + 26) % 26 + 'A';
        }
    }
}

int main()
{
    int key[26];
    char message[MAX_LEN];

    // Get user input for message
    printf("Enter message to encrypt (max %d characters):\n", MAX_LEN);
    fgets(message, MAX_LEN, stdin);

    // Generate encryption key
    generate_key(key);

    // Encrypt message
    encrypt(message, key);

    // Print encrypted message and key
    printf("Encrypted message: %s\n", message);
    printf("Encryption key:");
    for(int i=0; i<26; i++)
    {
        printf(" %d", key[i]);
    }
    printf("\n");

    // Decrypt message
    decrypt(message, key);

    // Print decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}