//FormAI DATASET v1.0 Category: Encryption ; Style: standalone
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

void encrypt(char* message, int key);
void decrypt(char* message, int key);

int main() {
    char message[MAX_LENGTH];
    int key;

    printf("Enter message to encrypt: ");
    fgets(message, MAX_LENGTH, stdin);
    message[strcspn(message, "\n")] = 0;

    printf("Enter key (1-25): ");
    scanf("%d", &key);

    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    decrypt(message, key);

    printf("Decrypted message: %s\n", message);

    return 0;
}

void encrypt(char* message, int key) {
    int i;
    char letter;

    for (i=0; message[i]!='\0'; ++i) {
        letter = message[i];

        if (letter >= 'a' && letter <= 'z') {
            letter = letter + key;

            if (letter > 'z') {
                letter = letter - 'z' + 'a' - 1;
            }

            message[i] = letter;
        }
        else if (letter >= 'A' && letter <= 'Z') {
            letter = letter + key;

            if (letter > 'Z') {
                letter = letter - 'Z' + 'A' - 1;
            }

            message[i] = letter;
        }
    }
}

void decrypt(char* message, int key) {
    int i;
    char letter;

    for (i=0; message[i]!='\0'; ++i) {
        letter = message[i];

        if (letter >= 'a' && letter <= 'z') {
            letter = letter - key;

            if (letter < 'a') {
                letter = letter + 'z' - 'a' + 1;
            }

            message[i] = letter;
        }
        else if (letter >= 'A' && letter <= 'Z') {
            letter = letter - key;

            if (letter < 'A') {
                letter = letter + 'Z' - 'A' + 1;
            }

            message[i] = letter;
        }
    }
}