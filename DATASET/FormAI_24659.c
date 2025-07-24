//FormAI DATASET v1.0 Category: Encryption ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char plainText[1000];
    char cipherText[1000];
    int i, shift;

    printf("Enter plaintext: ");
    gets(plainText);

    printf("Enter shift value: ");
    scanf("%d", &shift);
    getchar(); // clear input buffer

    // Encryption process
    for(i = 0; i < strlen(plainText); i++) {
        if(plainText[i] >= 'a' && plainText[i] <= 'z') {
            cipherText[i] = (plainText[i] - 'a' + shift) % 26 + 'a';
        } else if(plainText[i] >= 'A' && plainText[i] <= 'Z') {
            cipherText[i] = (plainText[i] - 'A' + shift) % 26 + 'A';
        } else {
            cipherText[i] = plainText[i];
        }
    }
    cipherText[i] = '\0';

    printf("Cipher text: %s\n", cipherText);

    return 0;
}