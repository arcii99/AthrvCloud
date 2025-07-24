//FormAI DATASET v1.0 Category: Encryption ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* plaintext, int shift);

int main(void) {
    char plaintext[100];
    int shift;

    printf("Enter the plaintext to be encrypted: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Enter the shift value for the encryption: ");
    scanf("%d", &shift);

    encrypt(plaintext, shift);

    printf("The encrypted text is: %s\n", plaintext);

    return 0;
}

void encrypt(char* plaintext, int shift) {
    int i;
    char c;

    for (i = 0; i < strlen(plaintext); i++) {
        c = plaintext[i];

        if (c >= 'a' && c <= 'z') {
            c = c + shift;

            if (c > 'z') {
                c = c - 'z' + 'a' - 1;
            }

            plaintext[i] = c;
        }
        else if (c >= 'A' && c <= 'Z') {
            c = c + shift;

            if (c > 'Z') {
                c = c - 'Z' + 'A' - 1;
            }

            plaintext[i] = c;
        }
    }
}