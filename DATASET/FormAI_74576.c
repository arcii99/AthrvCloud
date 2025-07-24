//FormAI DATASET v1.0 Category: Modern Encryption ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void encrypt(char *plaintext, char *ciphertext) {
    char key[] = "_sH<5#YX=N!tR9Pc^J@-a?bV7qG+3uK&j$LExz*mhZ8vU6QWfdewrg1%02i4o";
    int i, j;
    for (i = 0; i < strlen(plaintext); i++) {
        for (j = 0; j < strlen(key); j++) {
            if (plaintext[i] == key[j]) {
                ciphertext[i] = key[(j+10) % strlen(key)];
                break;
            }
        }
    }
}

void decrypt(char *ciphertext, char *plaintext) {
    char key[] = "_sH<5#YX=N!tR9Pc^J@-a?bV7qG+3uK&j$LExz*mhZ8vU6QWfdewrg1%02i4o";
    int i, j;
    for (i = 0; i < strlen(ciphertext); i++) {
        for (j = 0; j < strlen(key); j++) {
            if (ciphertext[i] == key[j]) {
                plaintext[i] = key[(j-10+strlen(key)) % strlen(key)];
                break;
            }
        }
    }
}

int main() {
    char plaintext[100] = "This is the original text";
    char ciphertext[100] = {0};
    char decrypted[100] = {0};
    
    encrypt(plaintext, ciphertext);
    printf("Encrypted Text: %s\n", ciphertext);
    
    decrypt(ciphertext, decrypted);
    printf("Decrypted Text: %s\n", decrypted);

    return 0;
}