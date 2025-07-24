//FormAI DATASET v1.0 Category: File Encyptor ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_STR_LEN 1000
#define ENCRYPTION_KEY 5

void encrypt(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        str[i] += ENCRYPTION_KEY;
        i++;
    }
}

void decrypt(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        str[i] -= ENCRYPTION_KEY;
        i++;
    }
}

int main(void) {
    char str[MAX_STR_LEN];

    // Get input from user
    printf("Enter a string to encrypt: ");
    fgets(str, MAX_STR_LEN, stdin);

    // Encrypt the string
    encrypt(str);
    printf("Encrypted string: %s", str);

    // Decrypt the string
    decrypt(str);
    printf("Decrypted string: %s", str);

    return 0;
}