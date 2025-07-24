//FormAI DATASET v1.0 Category: Encryption ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

void encrypt(char *msg, int key) {
    int i, len = strlen(msg);
    char temp[MAX_LEN];
    strncpy(temp, msg, MAX_LEN);

    for (i = 0; i < len; i++) {
        if (temp[i] >= 'a' && temp[i] <= 'z') {
            temp[i] = ((temp[i] - 'a') + key) % 26 + 'a';
        } else if (temp[i] >= 'A' && temp[i] <= 'Z') {
            temp[i] = ((temp[i] - 'A') + key) % 26 + 'A';
        }
    }

    printf("Encrypted message: %s\n", temp);
}

int main() {
    char message[MAX_LEN];
    int key;

    printf("Welcome to my C encryption program!\n\n");
    printf("Please enter the message you want to encrypt: ");
    fgets(message, MAX_LEN, stdin);

    printf("\nPlease enter the encryption key (a number between 1 and 25): ");
    scanf("%d", &key);

    if (key < 1 || key > 25) {
        printf("\nInvalid key! Please enter a number between 1 and 25.\n");
        return 1;
    }

    encrypt(message, key);

    printf("\nThank you for using my encryption program!\n");

    return 0;
}