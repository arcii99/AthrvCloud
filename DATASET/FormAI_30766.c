//FormAI DATASET v1.0 Category: modern Encryption ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random key
void generateKey(char key[], int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        key[i] = rand() % 26 + 'A';
    }
}

// Function to encrypt the plaintext using the key
void encrypt(char plaintext[], char key[], char ciphertext[])
{
    int len = strlen(plaintext);
    for (int i = 0; i < len; i++)
    {
        ciphertext[i] = (plaintext[i] + key[i]) % 26 + 'A';
    }
}

int main()
{
    char plaintext[] = "HELLO";
    int size = strlen(plaintext);

    char key[size];
    generateKey(key, size);

    char ciphertext[size];
    encrypt(plaintext, key, ciphertext);

    // Print the plaintext, key, and ciphertext
    printf("Plaintext: %s\n", plaintext);
    printf("Key: %s\n", key);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}