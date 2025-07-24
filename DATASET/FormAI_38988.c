//FormAI DATASET v1.0 Category: modern Encryption ; Style: grateful
#include <stdio.h>
#include <string.h>

// function to encrypt the string using XOR cipher
void encrypt(char message[], int key)
{
    int len = strlen(message);
    int i;
    for (i = 0; i < len; i++) {
        message[i] = message[i] ^ key; // xor operation with the key
    }

    printf("Your encrypted message is: %s\n", message);
}

int main()
{
    char message[1000], key_str[100];
    int key;
    
    printf("Enter your message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0; // remove trailing newline
    
    printf("Enter the key: ");
    fgets(key_str, sizeof(key_str), stdin);
    sscanf(key_str, "%d", &key);
    
    encrypt(message, key);

    return 0;
}