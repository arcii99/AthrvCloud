//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *plaintext, char *key, char *ciphertext) {
    int i, j, n, k;
    n = strlen(plaintext);
    k = strlen(key);
    for (i = 0, j = 0; i < n; i++, j++) {
        if (j == k) {
            j = 0;
        }
        ciphertext[i] = plaintext[i] + key[j];
        if (ciphertext[i] > 'z') {
            ciphertext[i] -= 26;
        }
    }
    ciphertext[i] = '\0';
}

void decrypt(char *ciphertext, char *key, char *plaintext) {
    int i, j, n, k;
    n = strlen(ciphertext);
    k = strlen(key);
    for (i = 0, j = 0; i < n; i++, j++) {
        if (j == k) {
            j = 0;
        }
        plaintext[i] = ciphertext[i] - key[j];
        if (plaintext[i] < 'a') {
            plaintext[i] += 26;
        }
    }
    plaintext[i] = '\0';
}

void recursive(char *str, int index, char *key) {
    char ciphertext[100] = "";
    char plaintext[100] = "";
    encrypt(str, key, ciphertext);
    decrypt(ciphertext, key, plaintext);
    if(strcmp(str, plaintext) != 0) {
      printf("The string cannot be encrypted and decrypted properly with this key. Try a different key.\n");
      exit(0);
    } else if (index == strlen(key)) {
        printf("Valid key found: %s\n", key);
        exit(0);
    } else {
        for (char c = 'a'; c <= 'z'; c++) {
            key[index] = c;
            recursive(str, index + 1, key);
        }
    }
}

int main() {
    char str[100], key[100];
    printf("Enter the string to be encrypted: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    printf("Enter a key to encrypt the string: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';
    recursive(str, 0, key);
    return 0;
}