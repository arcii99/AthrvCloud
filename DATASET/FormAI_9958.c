//FormAI DATASET v1.0 Category: Modern Encryption ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *str, int key) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] = (str[i] + key) % 256;
    }
}

void decrypt(char *str, int key) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] = (str[i] - key + 256) % 256;
    }
}

int main() {
    char message[100];
    int key;
    printf("Enter the message to be encrypted (Max 100 Characters): ");
    fgets(message, 100, stdin);
    printf("Enter the key: ");
    scanf("%d", &key);
    encrypt(message, key);
    printf("The encrypted message is: %s\n", message);
    decrypt(message, key);
    printf("The decrypted message is: %s\n", message);
    return 0;
}