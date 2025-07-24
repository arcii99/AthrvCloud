//FormAI DATASET v1.0 Category: File Encyptor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY 13 /* the Caesar cipher key */

void encrypt(char* plaintext, char* ciphertext);
void decrypt(char* ciphertext, char* plaintext);

int main() {
    char plaintext[50], ciphertext[50], decrypted[50];
    
    printf("Enter the plaintext to be encrypted: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    
    /* encrypt the plaintext and display the cipher text */
    encrypt(plaintext, ciphertext);
    printf("The encrypted text is: %s", ciphertext);
    
    /* decrypt the ciphertext and display the plaintext */
    decrypt(ciphertext, decrypted);
    printf("The decrypted text is: %s", decrypted);

    return 0;
}

void encrypt(char* plaintext, char* ciphertext) {
    int i;
    char ch;
    
    for(i = 0; i < strlen(plaintext); i++) {
        ch = plaintext[i];
        
        if(isalpha(ch)) { /* check if the character is alphabet */
            ch = toupper(ch); /* convert the character to uppercase */
            ch = ((ch - 65) + KEY) % 26 + 65; /* apply the Caesar cipher */
        }
        
        ciphertext[i] = ch; /* store the encrypted character */
    }
    
    ciphertext[i] = '\0'; /* terminate the ciphertext string */
}

void decrypt(char* ciphertext, char* plaintext) {
    int i;
    char ch;
    
    for(i = 0; i < strlen(ciphertext); i++) {
        ch = ciphertext[i];
        
        if(isalpha(ch)) { /* check if the character is alphabet */
            ch = toupper(ch); /* convert the character to uppercase */
            ch = ((ch - 65) - KEY + 26) % 26 + 65; /* apply the Caesar cipher */
        }
        
        plaintext[i] = ch; /* store the decrypted character */
    }
    
    plaintext[i] = '\0'; /* terminate the plaintext string */
}