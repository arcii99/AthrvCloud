//FormAI DATASET v1.0 Category: Encryption ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 5

char *encrypt(char *str, char key[KEY_SIZE]);

int main() {

    char str[] = "This is a secret message";
    char key[KEY_SIZE] = { 2, 6, 8, 1, 4 };
    char *encrypted_str = encrypt(str, key);
    printf("Original Message: %s\n", str);
    printf("Encrypted Message: %s\n", encrypted_str);

    return 0;
}

char *encrypt(char *str, char key[KEY_SIZE]) {

    int len = strlen(str);
    char *encrypted = (char *) malloc(len + 1);

    for (int i = 0; i < len; i++) {
        encrypted[i] = str[i] ^ key[i % KEY_SIZE];
    }

    encrypted[len] = '\0';
    return encrypted;

}