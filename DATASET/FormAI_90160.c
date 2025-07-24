//FormAI DATASET v1.0 Category: Encryption ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Cipher function to perform encryption
void cipher(char* plaintext, char* key, char* ciphertext) {
    int i, j, p_len, k_len;
    char key_char;
    
    // Getting lengths of plaintext and key
    p_len = strlen(plaintext);
    k_len = strlen(key);
    
    // Ciphering each character of plaintext
    for(i = 0, j = 0; i < p_len; i++, j++) {
        // Resetting key index if it exceeds key length
        if(j == k_len)
            j = 0;
            
        // Checking if plaintext character is alphabetic
        if(isalpha(plaintext[i])) {
            // Converting key character to uppercase
            key_char = toupper(key[j]);
            
            // Ciphering lowercase plaintext characters
            if(islower(plaintext[i]))
                ciphertext[i] = ((plaintext[i] - 'a') + (key_char - 'A')) % 26 + 'a';
            // Ciphering uppercase plaintext characters
            else
                ciphertext[i] = ((plaintext[i] - 'A') + (key_char - 'A')) % 26 + 'A';
        }
        // Copying non-alphabetic plaintext characters as they are
        else 
            ciphertext[i] = plaintext[i];
    }
    
    // Adding NULL at the end of ciphertext string
    ciphertext[i] = '\0';
}

int main() {
    char plaintext[100], key[100], ciphertext[100];
    
    // Getting plaintext and key input
    printf("Enter plaintext: ");
    scanf("%[^\n]%*c", plaintext);
    printf("Enter key: ");
    scanf("%[^\n]%*c", key);
    
    // Ciphering plaintext
    cipher(plaintext, key, ciphertext);
    
    // Displaying ciphertext
    printf("Ciphertext: %s\n", ciphertext);
    
    return 0;
}