//FormAI DATASET v1.0 Category: Text processing ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* C Program to implement a basic letter substitution cipher */
char* plain = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
char* cipher = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";

char* encrypt(char* message, int shift_key) {
    int len = strlen(message);
    char* ciphertext = (char*)malloc(sizeof(char) * (len+1));
    int i, j;

    for (i = 0; i < len; i++) {
        if (message[i] == ' ') {
            ciphertext[i] = ' ';
        }
        else {
            for (j = 0; j < strlen(plain); j++) {
                if (message[i] == plain[j]) {
                    ciphertext[i] = cipher[(j + shift_key) % strlen(cipher)];
                    break;
                }
            }
        }
    }

    ciphertext[i] = '\0';
    return ciphertext;
}

void main() {
    char message[100];
    int shift_key;
    printf("Enter message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter shift key: ");
    scanf("%d", &shift_key);
    char* ciphertext = encrypt(message, shift_key);
    printf("Encrypted message: %s\n", ciphertext);
    free(ciphertext);
}