//FormAI DATASET v1.0 Category: Encryption ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// function to encrypt message using basic substitution cipher
void basicSubstitutionCipher(char *message, int key) {
    for(int i = 0; message[i] != '\0'; ++i) {
        char ch = message[i];
        if(ch >= 'a' && ch <= 'z') {
            ch = (ch + key - 'a') % 26 + 'a';
        }
        else if(ch >= 'A' && ch <= 'Z') {
            ch = (ch + key - 'A') % 26 + 'A';
        }
        message[i] = ch;
    }
}

int main() {
    char message[1000];
    int key;

    printf("Enter message to encrypt: ");
    fgets(message, 1000, stdin);

    printf("Enter key for encryption: ");
    scanf("%d", &key);

    basicSubstitutionCipher(message, key);
    printf("Encrypted message: %s\n", message);
    
    return 0;
}