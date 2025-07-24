//FormAI DATASET v1.0 Category: Modern Encryption ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/* Function to encrypt the entered text using the Caesar Cipher */
void caesar_cipher(int shift, char *text) {
    int i;
    char ch;
    for(i = 0; i < strlen(text); i++) {
        /* Get the character from the text */
        ch = text[i];
        /* Encrypt the character using the shift */
        if(ch >= 'a' && ch <= 'z') {
            ch = (ch + shift - 'a') % 26 + 'a';
        } else if(ch >= 'A' && ch <= 'Z') {
            ch = (ch + shift - 'A') % 26 + 'A';
        }
        /* Replace the original character with the encrypted character */
        text[i] = ch;
    }
}

int main() {
    char text[100];
    int shift;
    /* Get the input from the user */
    printf("Enter the text to be encrypted: ");
    fgets(text, 100, stdin);
    printf("Enter the shift value: ");
    scanf("%d", &shift);
    /* Encrypt the text using the Caesar Cipher */
    caesar_cipher(shift, text);
    /* Print the encrypted text */
    printf("The encrypted text is: %s\n", text);
    return 0;
}