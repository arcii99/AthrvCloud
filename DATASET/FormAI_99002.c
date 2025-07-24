//FormAI DATASET v1.0 Category: Encryption ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Encryption function
void encrypt(char* message, char* key) {
    int messageLength = strlen(message);
    int keyLength = strlen(key);

    for (int i = 0, j = 0; i < messageLength; i++, j++) {
        if (j == keyLength) {
            j = 0;
        }
        message[i] += key[j];
    }
}

//Main function
int main() {
    char message[100];
    char key[100];

    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);

    printf("Enter encryption key: ");
    fgets(key, 100, stdin);

    //Removing \n from fgets input
    message[strcspn(message, "\n")] = 0;
    key[strcspn(key, "\n")] = 0;

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    return 0;
}