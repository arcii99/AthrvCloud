//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: satisfied
/*
 * A unique implementation of Caesar cipher in C programming language
 * Author: John Doe
 */

#include <stdio.h>
#include <ctype.h>

#define SHIFT 3

char caesar_encrypt(char ch, int key);

int main() {
    char message[1000];
    int key = SHIFT;
    
    printf("Enter a message to encrypt: ");
    fgets(message, 1000, stdin);
    
    printf("Encrypted message: ");
    for(int i = 0; message[i] != '\0'; ++i) {
        putchar(caesar_encrypt(message[i], key));
    }
    
    printf("\n");
    
    return 0;
}

char caesar_encrypt(char ch, int key) {
    if(!isalpha(ch)) {
        return ch;
    }
    
    if(isupper(ch)) {
        return (((ch - 'A') + key) % 26) + 'A';
    }
    
    return (((ch - 'a') + key) % 26) + 'a';
}