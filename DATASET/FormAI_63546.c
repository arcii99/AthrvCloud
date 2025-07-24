//FormAI DATASET v1.0 Category: Modern Encryption ; Style: beginner-friendly
#include<stdio.h>
#include<string.h>

void encrypt(char message[], int key);

int main() {
    char message[100];
    int key;

    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);

    printf("Enter the key: ");
    scanf("%d", &key);

    encrypt(message, key);

    printf("Encrypted message: %s", message);

    return 0;
}

void encrypt(char message[], int key) {
    int i, length = strlen(message);

    for(i = 0; i < length; ++i) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (message[i] + key - 'a') % 26 + 'a';
        }
        else if(message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (message[i] + key - 'A') % 26 + 'A';
        }
    }
}