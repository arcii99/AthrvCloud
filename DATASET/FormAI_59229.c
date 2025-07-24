//FormAI DATASET v1.0 Category: Encryption ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// function to encrypt the message
void encrypt(char* message, int key) {
    if(key < 0) {
        key = 26 - (-key % 26);
    }
    for(int i = 0; i < strlen(message); ++i) {
        // encrypt only uppercase and lowercase alphabets A-Z or a-z
        if(message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = 'A' + (message[i] - 'A' + key) % 26;
        }
        else if(message[i] >= 'a' && message[i] <= 'z') {
            message[i] = 'a' + (message[i] - 'a' + key) % 26;
        }
    }
}

int main() {
    char message[100];
    int key;
    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);
    message[strcspn(message, "\n")] = 0; // remove newline character from input buffer
    printf("Enter key: ");
    scanf("%d", &key);
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);
    return 0;
}