//FormAI DATASET v1.0 Category: File Encyptor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *message, int key);

int main() {
    char message[1000];
    int key;

    printf("Enter a message to encrypt: ");
    fgets(message, 1000, stdin);

    printf("Enter the encryption key: ");
    scanf("%d", &key);

    encrypt(message, key);

    printf("Your encrypted message is: %s", message);

    return 0;
}

void encrypt(char *message, int key) {
    int i, gap;
    char encrypted_letter;

    for(i = 0; message[i] != '\0'; i++) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            gap = 'a';
        } else if(message[i] >= 'A' && message[i] <= 'Z') {
            gap = 'A';
        } else continue;

        encrypted_letter = (message[i] - gap + key) % 26 + gap;

        message[i] = encrypted_letter;
    }
}