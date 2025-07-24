//FormAI DATASET v1.0 Category: Modern Encryption ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ENCRYPTION_KEY 5

void encrypt(char *original, char *encrypted) {
    int i, length = strlen(original);
    
    for(i=0; i<length; i++) {
        // Shift each character by the encryption key
        encrypted[i] = (char) ((original[i] + ENCRYPTION_KEY) % 256);
    }
    encrypted[i] = '\0';
}

void decrypt(char *encrypted, char *decrypted) {
    int i, length = strlen(encrypted);
    
    for(i=0; i<length; i++) {
        // Shift each character back by the encryption key
        decrypted[i] = (char) ((encrypted[i] - ENCRYPTION_KEY) % 256);
    }
    decrypted[i] = '\0';
}

int main() {
    char original[100], encrypted[100], decrypted[100];
    srand(time(NULL));
    
    printf("Enter a message to encrypt: ");
    fgets(original, 100, stdin);
    original[strcspn(original, "\n")] = 0;
    
    encrypt(original, encrypted);
    
    printf("The encrypted message is: ");
    puts(encrypted);
    
    decrypt(encrypted, decrypted);
    
    printf("The decrypted message is: ");
    puts(decrypted);
    
    return 0;
}