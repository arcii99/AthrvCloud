//FormAI DATASET v1.0 Category: Encryption ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

char lowerAlphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char upperAlphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char numbers[10] = {'0','1','2','3','4','5','6','7','8','9'};
char symbols[15] = {'.', ',', '!', '=', '+', '-', '*', '/', '<', '>', '$', '&', '@', '%', '#'};

char generateRandom(char array[], int size) {
    int randomIndex = (rand() % size);
    return array[randomIndex];
}

void generateKey(char key[], int keyLength) {
    srand(time(0));
    for (int i = 0; i < keyLength; i++) {
        if (i < 10) {
            key[i] = generateRandom(numbers, 10);
        } else if (i >= 10 && i < 20) {
            key[i] = generateRandom(lowerAlphabet, 26);
        } else if (i >= 20 && i < 30) {
            key[i] = generateRandom(upperAlphabet, 26);
        } else {
            key[i] = generateRandom(symbols, 15);
        }
    }
    key[keyLength] = '\0';
}

void encrypt(char *message, int messageLength, char *key, int keyLength) {
    for (int i = 0; i < messageLength; i++) {
        message[i] ^= key[i%keyLength];
    }
}

int main() {
    char message[100], key[31];
    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);

    printf("Generating key...\n");
    generateKey(key, 30);
    printf("Key generated: %s\n", key);

    printf("Encrypting message...\n");
    encrypt(message, strlen(message), key, strlen(key));

    printf("Encrypted message: %s\n", message);
    printf("Key used: %s\n", key);

    return 0;
}