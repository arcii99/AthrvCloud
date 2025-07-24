//FormAI DATASET v1.0 Category: Encryption ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to this immersive program demonstrating C Encryption!\n");
    
    char message[100];
    int key;
    
    printf("Enter message you want to encrypt: ");
    gets(message);
    
    printf("Enter the key for encryption (must be an integer): ");
    scanf("%d", &key);
    
    int i = 0;
    
    while (message[i] != '\0') {
        message[i] = message[i] + key;
        i++;
    }
    
    printf("Encrypted message: %s\n", message);
    
    i = 0;
    
    while (message[i] != '\0') {
        message[i] = message[i] - key;
        i++;
    }
    
    printf("Decrypted message: %s\n", message);
    
    printf("Thank you for using this program!\n");
    
    return 0;
}