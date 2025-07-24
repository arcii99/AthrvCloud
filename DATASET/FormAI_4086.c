//FormAI DATASET v1.0 Category: Browser Plugin ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

void encrypt(char *str, int key) {
    while (*str != '\0') {
        *str = *str + key;
        str++;
    }
}

void decrypt(char *str, int key) {
    while (*str != '\0') {
        *str = *str - key;
        str++;
    }
}

int main() {
    char browser[20];
    int key;

    printf("Enter the name of your browser: ");
    scanf("%s", browser);

    printf("Enter the encryption key: ");
    scanf("%d", &key);

    encrypt(browser, key);
    printf("Encrypted browser name: %s\n", browser);

    decrypt(browser, key);
    printf("Decrypted browser name: %s\n", browser);

    return 0;
}