//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void encrypt(char *message, int key) {
    int i;
    for(i = 0; i < strlen(message); i++) {
        message[i] = (char)(((int)message[i] + key) % 128);
    }
}

void decrypt(char *message, int key) {
    int i;
    for(i = 0; i < strlen(message); i++) {
        message[i] = (char)(((int)message[i] - key + 128) % 128);
    }
}

int main() {
    char message[] = "Hello, world!";
    int key = 3;
    printf("Original message: %s\n", message);
    
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);
    
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}