//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to encrypt text using modern encryption
void modernEncrypt(char *text, int key) {
    int n = strlen(text);

    for (int i = 0; i < n; i++) {
        if (text[i] == ' ') continue;  // skip spaces

        int c = (text[i] - 'a' + key) % 26;
        text[i] = c + 'a';
    }
}

// function to decrypt text using modern encryption
void modernDecrypt(char *text, int key) {
    int n = strlen(text);

    for (int i = 0; i < n; i++) {
        if (text[i] == ' ') continue;  // skip spaces

        int c = (text[i] - 'a' - key + 26) % 26;
        text[i] = c + 'a';
    }
}

int main() {
    char *text = "hello world";
    int key = 5;

    printf("Original Text: %s\n", text);

    modernEncrypt(text, key);
    printf("Encrypted Text: %s\n", text);

    modernDecrypt(text, key);
    printf("Decrypted Text: %s\n", text);

    return 0;
}