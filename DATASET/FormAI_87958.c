//FormAI DATASET v1.0 Category: modern Encryption ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

// function to perform encryption
void encrypt(char* message, int key) {
    int i;
    char ch;
    
    for (i = 0; message[i] != '\0'; i++) {
        ch = message[i];
        
        // Encrypt lowercase characters
        if (ch >= 'a' && ch <= 'z') {
            ch = ch + key;
            
            if (ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }
            
            message[i] = ch;
        }
        // Encrypt uppercase characters
        else if (ch >= 'A' && ch <= 'Z') {
            ch = ch + key;
            
            if (ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }
            
            message[i] = ch;
        }
    }
}

// function to perform decryption
void decrypt(char* message, int key) {
    int i;
    char ch;
    
    for (i = 0; message[i] != '\0'; i++) {
        ch = message[i];
        
        // Decrypt lowercase characters
        if (ch >= 'a' && ch <= 'z') {
            ch = ch - key;
            
            if (ch < 'a') {
                ch = ch + 'z' - 'a' + 1;
            }
            
            message[i] = ch;
        }
        // Decrypt uppercase characters
        else if (ch >= 'A' && ch <= 'Z') {
            ch = ch - key;
            
            if (ch < 'A') {
                ch = ch + 'Z' - 'A' + 1;
            }
            
            message[i] = ch;
        }
    }
}

int main() {
    char message[100];
    int key;
    int choice;
    
    printf("Enter a message to encrypt: ");
    gets(message);
    
    printf("Enter the encryption key: ");
    scanf("%d", &key);
    
    printf("Choose an option:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            encrypt(message, key);
            printf("Encrypted message: %s\n", message);
            break;
        case 2:
            decrypt(message, key);
            printf("Decrypted message: %s\n", message);
            break;
        default:
            printf("Invalid choice!");
    }
    
    return 0;
}