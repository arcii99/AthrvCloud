//FormAI DATASET v1.0 Category: Encryption ; Style: multivariable
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 100

void encryption(char message[MAX], char key[MAX], char encrypted[MAX]) {
    int len = strlen(message), i;
    
    for (i = 0; i < len; ++i) {
        encrypted[i] = ((message[i] - 97 + key[i%strlen(key)] - 97) % 26) + 97;
    }
    
    encrypted[i] = '\0';
}

void decryption(char encrypted[MAX], char key[MAX], char decrypted[MAX]) {
    int len = strlen(encrypted), i;
    
    for (i = 0; i < len; ++i) {
        decrypted[i] = ((encrypted[i] - 97 - (key[i%strlen(key)] - 97) + 26) % 26) + 97;
    }
    
    decrypted[i] = '\0';
}

int main() {
    char message[MAX], key[MAX], encrypted[MAX], decrypted[MAX];
    
    printf("Enter the message to encrypt: ");
    scanf("%[^\n]s", message);
    fflush(stdin); // clear input buffer
    
    printf("Enter the key to encrypt: ");
    scanf("%[^\n]s", key);
    fflush(stdin); // clear input buffer
    
    encryption(message, key, encrypted);
    printf("Encrypted message: %s\n", encrypted);
    
    decryption(encrypted, key, decrypted);
    printf("Decrypted message: %s\n", decrypted);
    
    return 0;
}