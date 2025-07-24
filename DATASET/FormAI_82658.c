//FormAI DATASET v1.0 Category: modern Encryption ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define KEY_SIZE 16
#define MESSAGE_SIZE 1000

char generate_key() {
    char key[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=[]{};':\",./<>?";
    int index = rand() % strlen(key);
    return key[index];
}

void generate_random_key(char *key) {
    for(int i = 0; i < KEY_SIZE; i++) {
        key[i] = generate_key();
    }
}

void encrypt_message(char *key, char *message, char *encrypted_message) {
    int key_size = strlen(key);
    int message_size = strlen(message);
    int key_index = 0;
    for(int i = 0; i < message_size; i++) {
        char encrypted_char = message[i] ^ key[key_index];
        encrypted_message[i] = encrypted_char;
        key_index = (key_index + 1) % key_size;
    }
    encrypted_message[message_size] = '\0';
}

void decrypt_message(char *key, char *encrypted_message, char *decrypted_message) {
    int key_size = strlen(key);
    int message_size = strlen(encrypted_message);
    int key_index = 0;
    for(int i = 0; i < message_size; i++) {
        char decrypted_char = encrypted_message[i] ^ key[key_index];
        decrypted_message[i] = decrypted_char;
        key_index = (key_index + 1) % key_size;
    }
    decrypted_message[message_size] = '\0';
}

int main() {
    srand(time(NULL));

    char key[KEY_SIZE + 1];
    generate_random_key(key);

    char message[MESSAGE_SIZE];
    printf("Enter your message: ");
    fgets(message, sizeof(message), stdin);

    char encrypted_message[MESSAGE_SIZE];
    encrypt_message(key, message, encrypted_message);
    printf("Encrypted message: %s\n", encrypted_message);

    char decrypted_message[MESSAGE_SIZE];
    decrypt_message(key, encrypted_message, decrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}