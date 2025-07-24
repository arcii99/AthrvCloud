//FormAI DATASET v1.0 Category: Encryption ; Style: configurable
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

void encrypt(char* message, int key) {
    int i;
    for(i = 0; message[i] != '\0'; ++i)
        message[i] += key % 26;
}

void decrypt(char* message, int key) {
    int i;
    for(i = 0; message[i] != '\0'; ++i)
        message[i] -= key % 26;
}

int main() {
    char message[MAX_LENGTH];
    int key, choice;

    printf("Enter a message to encrypt: ");
    fgets(message, MAX_LENGTH, stdin);
    printf("Enter a key value (0-25): ");
    scanf("%d", &key);

    printf("\nChoose an option:\n");
    printf("1. Encrypt message\n");
    printf("2. Decrypt message\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if(choice == 1) {
        encrypt(message, key);
        printf("\nEncrypted message: %s", message);
    }
    else if(choice == 2) {
        decrypt(message, key);
        printf("\nDecrypted message: %s", message);
    }
    else {
        printf("\nInvalid choice!");
    }

    return 0;
}