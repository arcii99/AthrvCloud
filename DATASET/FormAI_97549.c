//FormAI DATASET v1.0 Category: modern Encryption ; Style: calm
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

void encrypt(char message[], int key) {
    int i;
    
    for (i = 0; message[i] != '\0'; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a' + key) % 26) + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A' + key) % 26) + 'A';
        }
    }
}

int main() {
    char message[MAX_SIZE];
    int key;
    
    printf("Enter a message to encrypt: ");
    fgets(message, MAX_SIZE, stdin);
    
    printf("Enter a key for encryption: ");
    scanf("%d", &key);
    
    encrypt(message, key);
    
    printf("Encrypted message: %s", message);
    
    return 0;
}