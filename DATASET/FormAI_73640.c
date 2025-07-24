//FormAI DATASET v1.0 Category: modern Encryption ; Style: calm
#include <stdio.h>
#include <string.h>

void caesarEncrypt(char message[], int key);

int main() {
    char message[100];
    int key;
    
    // Prompt the user to enter the message and key
    printf("Enter message: ");
    fgets(message, 100, stdin);
    printf("Enter key: ");
    scanf("%d", &key);
    
    // Call the caesarEncrypt function to encrypt the message
    caesarEncrypt(message, key);
    
    // Print the encrypted message
    printf("Encrypted message: %s", message);
    
    return 0;
}

void caesarEncrypt(char message[], int key) {
    int i, length = strlen(message);
    
    for(i = 0; i < length; i++) {
        char c = message[i];
        
        if(c >= 'a' && c <= 'z') {
            // Shift the lowercase letters by the key value
            c = (c - 'a' + key) % 26 + 'a';
        }
        else if(c >= 'A' && c <= 'Z') {
            // Shift the uppercase letters by the key value
            c = (c - 'A' + key) % 26 + 'A';
        }
        
        message[i] = c;
    }
}