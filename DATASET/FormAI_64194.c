//FormAI DATASET v1.0 Category: Encryption ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000 // Maximum length of input string

// Function to encrypt the input string
void encrypt(char string[], int key)
{
    int len = strlen(string); // Length of input string
    int i;

    for(i=0; i<len; i++) {
        string[i] = ((string[i] - 'a' + key) % 26) + 'a'; // Encrypt each character by adding key to ASCII value
    }
}

int main()
{
    char input[MAX_LEN];
    int key;

    printf("Enter a string to encrypt: ");
    fgets(input, MAX_LEN, stdin); // Read input string

    printf("Enter key for encryption: ");
    scanf("%d", &key); // Read encryption key

    encrypt(input, key); // Encrypt the input string

    printf("Encrypted string: %s", input);

    return 0;
}