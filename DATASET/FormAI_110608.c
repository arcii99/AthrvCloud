//FormAI DATASET v1.0 Category: Encryption ; Style: calm
#include <stdio.h>
#include <string.h>

// Encryption function
void encrypt(char *str) {
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        str[i] += 3; // Shift each character by 3 places
    }
}

// Decryption function
void decrypt(char *str) {
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        str[i] -= 3; // Shift each character back by 3 places
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    gets(str);
    
    // Encrypt the string
    encrypt(str);
    printf("Encrypted string: %s\n", str);
    
    // Decrypt the string
    decrypt(str);
    printf("Decrypted string: %s\n", str);
    
    return 0;
}