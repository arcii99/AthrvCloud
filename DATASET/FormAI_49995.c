//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Cyberpunk
#include <stdio.h>

#define CYBERPUNK_MODE 0b11110000
#define HACK_MODE 0b00001111

void hack(char* message, int key) {
    int i;
    for (i = 0; message[i] != '\0'; ++i) {
        message[i] = message[i] ^ key;
    }

    printf("Message successfully hacked with key: %d\n", key);
    printf("Hacked message: %s\n", message);
}

void encrypt(char* message) {
    int i;
    for (i = 0; message[i] != '\0'; ++i) {
        message[i] = message[i] & CYBERPUNK_MODE;
    }

    printf("Message encrypted successfully\n");
    printf("Encrypted message: %s\n", message);
}

void decrypt(char* message) {
    int i;
    for (i = 0; message[i] != '\0'; ++i) {
        message[i] = message[i] | HACK_MODE;
    }

    printf("Message decrypted successfully\n");
    printf("Decrypted message: %s\n", message);
}

int main() {
    char message[] = "Hack the Planet!";
    int key = 123;

    encrypt(message);

    hack(message, key);

    decrypt(message);

    return 0;
}