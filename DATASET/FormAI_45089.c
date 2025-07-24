//FormAI DATASET v1.0 Category: Encryption ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* message, int key);

int main() {
    char message[100];
    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);
    int key;
    printf("Enter an integer key to encrypt the message: ");
    scanf("%d", &key);
    encrypt(message, key);
    printf("Encrypted message: %s", message);
    return 0;
}

void encrypt(char* message, int key) {
    int len = strlen(message);
    for(int i = 0; i < len; i++) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a' + key) % 26) + 'a';
        } 
        else if(message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A' + key) % 26) + 'A';
        }
    }
}