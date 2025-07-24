//FormAI DATASET v1.0 Category: Encryption ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>

void encrypt(char *plaintext, int key); // function prototype for encryption
void decrypt(char *ciphertext, int key); // function prototype for decryption

int main()
{
    char message[100]; // declare message variable
    int key; // declare key variable
    
    printf("Enter message to encrypt: ");
    fgets(message, sizeof(message), stdin); // get message input
    printf("Enter key: ");
    scanf("%d", &key); // get key input
    getchar(); // clear input buffer
    
    encrypt(message, key); // call encryption function
    printf("Encrypted message: %s", message); // print encrypted message
    
    decrypt(message, key); // call decryption function
    printf("Decrypted message: %s", message); // print decrypted message
    
    return 0;
}

void encrypt(char *plaintext, int key)
{
    int i; // declare loop variable
    
    for(i=0; i<strlen(plaintext); i++) // loop through each character in message
    {
        if(plaintext[i] >= 'a' && plaintext[i] <= 'z') // check if character is lowercase letter
        {
            plaintext[i] = ((plaintext[i] - 'a') + key) % 26 + 'a'; // shift character by key amount, wrap around if necessary
        }
        else if(plaintext[i] >= 'A' && plaintext[i] <= 'Z') // check if character is uppercase letter
        {
            plaintext[i] = ((plaintext[i] - 'A') + key) % 26 + 'A'; // shift character by key amount, wrap around if necessary
        }
    }
}

void decrypt(char *ciphertext, int key)
{
    int i; // declare loop variable
    
    for(i=0; i<strlen(ciphertext); i++) // loop through each character in message
    {
        if(ciphertext[i] >= 'a' && ciphertext[i] <= 'z') // check if character is lowercase letter
        {
            ciphertext[i] = ((ciphertext[i] - 'a') - key + 26) % 26 + 'a'; // shift character back by key amount, wrap around if necessary
        }
        else if(ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') // check if character is uppercase letter
        {
            ciphertext[i] = ((ciphertext[i] - 'A') - key + 26) % 26 + 'A'; // shift character back by key amount, wrap around if necessary
        }
    }
}