//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: creative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEN 256
#define KEY_LEN 16

// Function to generate a random key
void generate_key(char key[KEY_LEN + 1]) {
    srand(time(NULL));
    int i, random_num;
    for (i = 0; i < KEY_LEN; i++) {
        random_num = rand() % 26;
        key[i] = 'a' + random_num;
    }
    key[i] = '\0';
}

// Function to encrypt a message using a given key
void encrypt(char message[MAX_LEN], char key[KEY_LEN], char cipher[MAX_LEN]) {
    int i;
    for (i = 0; i < strlen(message); i++) {
        if (message[i] == ' ')
            cipher[i] = ' ';
        else
            cipher[i] = ((message[i] - 'a') + (key[i % KEY_LEN] - 'a')) % 26 + 'a';
    }
    cipher[i] = '\0';
}

// Function to decrypt a cipher using a given key
void decrypt(char cipher[MAX_LEN], char key[KEY_LEN], char message[MAX_LEN]) {
    int i;
    for (i = 0; i < strlen(cipher); i++) {
        if (cipher[i] == ' ')
            message[i] = ' ';
        else
            message[i] = ((cipher[i] - 'a') - (key[i % KEY_LEN] - 'a') + 26) % 26 + 'a';
    }
    message[i] = '\0';
}

int main() {
    char message[MAX_LEN], key[KEY_LEN + 1], cipher[MAX_LEN], decrypted[MAX_LEN];

    printf("Enter a message to encrypt: ");
    fgets(message, MAX_LEN, stdin);
    message[strcspn(message, "\n")] = 0;

    generate_key(key);

    encrypt(message, key, cipher);
    printf("Encrypted message: %s\n", cipher);

    decrypt(cipher, key, decrypted);
    printf("Decrypted message: %s\n", decrypted);

    return 0;
}