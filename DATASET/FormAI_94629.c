//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 100000

char *encrypt(char *text, int length, char *key, int key_len) {
    srand(time(NULL));
    char *encrypted = (char *)malloc(length * sizeof(char));
    int rand_num = rand();
    for (int i = 0; i < length; i++) {
        encrypted[i] = text[i] ^ key[i % key_len] ^ rand_num;
        rand_num = rand();
    }
    return encrypted;
}

char *decrypt(char *encrypted, int length, char *key, int key_len) {
    char *decrypted = (char *)malloc(length * sizeof(char));
    int rand_num = rand();
    for (int i = 0; i < length; i++) {
        decrypted[i] = encrypted[i] ^ key[i % key_len] ^ rand_num;
        rand_num = rand();
    }
    return decrypted;
}

int main() {
    char message[MAX_LENGTH];
    char key[MAX_LENGTH];
    printf("Enter your message: ");
    fgets(message, MAX_LENGTH, stdin);
    printf("Enter your encryption key: ");
    fgets(key, MAX_LENGTH, stdin);
    int message_len = strlen(message);
    int key_len = strlen(key);
    char *encrypted = encrypt(message, message_len, key, key_len);
    char *decrypted = decrypt(encrypted, message_len, key, key_len);
    printf("Original message: %s", message);
    printf("Encrypted message: %s", encrypted);
    printf("Decrypted message: %s", decrypted);
    free(encrypted);
    free(decrypted);
    return 0;
}