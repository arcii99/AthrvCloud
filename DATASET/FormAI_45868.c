//FormAI DATASET v1.0 Category: Encryption ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt(char* str, int key);

int main() {
    char message[] = "This is a secret message!";
    int key = 3;

    char* encrypted = encrypt(message, key);

    printf("Secret message: %s\n", message);
    printf("Encrypted message: %s\n", encrypted);

    free(encrypted);
    return 0;
}

char* encrypt(char* str, int key) {
    int len = strlen(str);

    char* encrypted = malloc(sizeof(char) * (len + 1));
    encrypted[len] = '\0';

    for (int i = 0; i < len; i++) {
        if (str[i] == ' ') {
            encrypted[i] = ' ';
        } else {
            int ascii = (int) str[i] + key;
            if (ascii > 90 && ascii < 97) {
                ascii = (ascii - 90) + 64;
            } else if (ascii > 122) {
                ascii = (ascii - 122) + 96;
            }
            char c = (char) ascii;
            encrypted[i] = c;
        }
    }

    return encrypted;
}