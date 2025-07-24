//FormAI DATASET v1.0 Category: modern Encryption ; Style: excited
#include <stdio.h>
#include <string.h>

void encrypt(char message[], int key) {
    int i;
    int length = strlen(message);
    char crypted[length];
    
    for (i = 0; i < length; i++) {
        crypted[i] = message[i] + key;
    }
    crypted[i] = '\0';
    
    printf("Original message: %s\n", message);
    printf("Encrypted message: %s\n", crypted);
}

int main() {
    char message[100];
    int key;
    
    printf("Enter a message to encrypt: ");
    scanf("%[^\n]", message);
    
    printf("Enter a key: ");
    scanf("%d", &key);

    encrypt(message, key);

    return 0;
}