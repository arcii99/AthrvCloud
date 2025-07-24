//FormAI DATASET v1.0 Category: Modern Encryption ; Style: satisfied
#include <stdio.h>
#include <string.h>

void encrypt(char* message, int key){
    int i;
    int len = strlen(message);
    for(i = 0; i < len; i++){
        message[i] = message[i] + key;
    }
}

void decrypt(char* message, int key){
    int i;
    int len = strlen(message);
    for(i = 0; i < len; i++){
        message[i] = message[i] - key;
    }
}

int main() {
    char message[100];
    int key;

    printf("Enter a message: ");
    scanf("%s", message);

    printf("Enter a key (positive integer): ");
    scanf("%d", &key);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}