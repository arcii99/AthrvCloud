//FormAI DATASET v1.0 Category: Modern Encryption ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int encrypt(char *plaintext, char *password, char *ciphertext);

int main() {
    char plaintext[100], password[20];
    printf("Enter plaintext message: ");
    fgets(plaintext, 100, stdin);
    printf("Enter password: ");
    fgets(password, 20, stdin);

    char ciphertext[100];
    encrypt(plaintext, password, ciphertext);
    printf("Ciphertext: %s", ciphertext);

    return 0;
}

int encrypt(char *plaintext, char *password, char *ciphertext) {
    int i, j, k = 0;
    int len_plaintext = strlen(plaintext), len_password = strlen(password);
    for(i = 0; i < len_plaintext; i++) {
        if(k == len_password) {
            k = 0;
        }
        int ascii_val = ((int)plaintext[i] + (int)password[k]) % 128;
        ciphertext[i] = (char)ascii_val;
        k++;
    }
    ciphertext[i] = '\0';

    return 0;
}