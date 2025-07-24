//FormAI DATASET v1.0 Category: Encryption ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

char encrypt(char c, int key);
void encryptText(char text[], int key, char encryptedText[]);
void decryptText(char encryptedText[], int key, char decryptedText[]);

int main() {
    int key = 5;
    char text[MAX_LENGTH], encryptedText[MAX_LENGTH], decryptedText[MAX_LENGTH];
    printf("Enter text to encrypt:\n");
    fgets(text, MAX_LENGTH, stdin);
    encryptText(text, key, encryptedText);
    printf("Encrypted text: %s\n", encryptedText);
    decryptText(encryptedText, key, decryptedText);
    printf("Decrypted text: %s\n", decryptedText);
    return 0;
}

char encrypt(char c, int key) {
    if(isalpha(c)) {
        if(isupper(c)) {
            return ((c - 'A' + key) % 26 + 'A');
        } else {
            return ((c - 'a' + key) % 26 + 'a');
        }
    } else {
        return c;
    }
}

void encryptText(char text[], int key, char encryptedText[]) {
    int i;
    for(i = 0; i < strlen(text); i++) {
        encryptedText[i] = encrypt(text[i], key);
    }
    encryptedText[i] = '\0';
}

void decryptText(char encryptedText[], int key, char decryptedText[]) {
    int i;
    for(i = 0; i < strlen(encryptedText); i++) {
        decryptedText[i] = encrypt(encryptedText[i], 26 - key);
    }
    decryptedText[i] = '\0';
}