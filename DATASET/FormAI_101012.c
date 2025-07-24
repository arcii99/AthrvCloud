//FormAI DATASET v1.0 Category: Encryption ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define KEY 13 // The Key for ROT13 Algorithm

// The function to encrypt the text using ROT13 Algorithm
void encryptText(char* text) {
    int length = strlen(text);
    
    for(int i=0; i<length; i++) {
        if(isalpha(text[i])) { // Check if the current character is alphabet or not
            if(isupper(text[i])) { // Check if the current character is uppercase or not
                text[i] = ((text[i] - 'A') + KEY) % 26 + 'A'; // Apply the ROT13 Algorithm
            }
            else {
                text[i] = ((text[i] - 'a') + KEY) % 26 + 'a'; // Apply the ROT13 Algorithm
            }
        }
    }
}

int main() {
    char text[100];
    printf("Enter the text to be encrypted: ");
    fgets(text, sizeof(text), stdin); // Reads the input text
    
    encryptText(text); // Encrypt the input text using ROT13 Algorithm

    printf("Encrypted Text: %s", text);
    
    return 0;
}