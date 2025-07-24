//FormAI DATASET v1.0 Category: Encryption ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

char* encrypt(char* message, int key) {
    int len = strlen(message);
    char* encrypted_message = (char*) malloc(len * sizeof(char));
    
    for (int i = 0; i < len; i++) {
        char c = message[i];
        
        if (c >= 'a' && c <= 'z') {
            c = ((c - 'a') + key) % 26 + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            c = ((c - 'A') + key) % 26 + 'A';
        }
        
        encrypted_message[i] = c;
    }
    
    return encrypted_message;
}

int main() {
    char message[100];
    int key;
    
    printf("Enter a message to encrypt: ");
    scanf("%[^\n]%*c", message);
    
    printf("Enter a key for encryption: ");
    scanf("%d", &key);
    
    char* encrypted_message = encrypt(message, key);
    
    printf("Encrypted message: %s\n", encrypted_message);
    
    free(encrypted_message);
    
    return 0;
}