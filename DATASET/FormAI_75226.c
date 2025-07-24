//FormAI DATASET v1.0 Category: Encryption ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt(char* message, int key) {
    int length = strlen(message);
    char* encrypted = (char*)malloc(sizeof(char) * length); // allocate memory for encrypted message
    for (int i = 0; i < length; i++) {
        encrypted[i] = (message[i] + key) % 26 + 'A'; // shift each character in the message by the key value and perform modulo 26 to wrap around the alphabet
    }
    encrypted[length] = '\0'; // terminate the string with a null character
    return encrypted;
}

int main() {
    char message[] = "HELLO WORLD";
    int key = 3;
    char* encrypted = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted);
    free(encrypted); // free the memory used by the encrypted message
    return 0;
}