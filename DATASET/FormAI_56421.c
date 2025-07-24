//FormAI DATASET v1.0 Category: modern Encryption ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// The Caesar Cipher is a substitution cipher that replaces each character
// in the plaintext by a fixed number of positions down the alphabet.
// For example, with a shift of 1, A would be replaced by B, B would become C, and so on.

// Encryption function that takes in a string and a shift value and returns the encrypted string
char* caesarCipherEncrypt(char* str, int shift) {
    int length = strlen(str);
    char* encryptedString = (char*) malloc((length+1) * sizeof(char));
    
    for (int i = 0; i < length; i++) {
        if(isalpha(str[i])) {
            if(isupper(str[i])) {
                encryptedString[i] = ((str[i] - 'A') + shift) % 26 + 'A';
            }
            else {
                encryptedString[i] = ((str[i] - 'a') + shift) % 26 + 'a';
            }
        }
        else {
            encryptedString[i] = str[i];
        }
    }
    
    encryptedString[length] = '\0';
    return encryptedString;
}

int main() {
    char message[100];
    int shift;
    printf("Enter message to encrypt: ");
    scanf("%[^\n]%*c", message); // read in entire string including spaces
    printf("Enter shift: ");
    scanf("%d", &shift);
    
    char *encrypted = caesarCipherEncrypt(message, shift);
    printf("Encrypted message: %s\n", encrypted);
    free(encrypted); // clear allocated memory
    
    return 0;
}