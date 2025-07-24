//FormAI DATASET v1.0 Category: Modern Encryption ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
 
/* This encryption program uses a modified Caesar Cipher and a random key generator */
 
char* encrypt(char* message, char* keygen);
char* decrypt(char* message, char* key);
char* generate_key(int length);
 
int main() {
    printf("Enter message to encrypt: ");
    char message[1000];
    fgets(message, 1000, stdin);
 
    printf("Encrypting message...\n");
    char* key = generate_key(strlen(message) - 1);
    char* encrypted_message = encrypt(message, key);
 
    printf("Encrypted message: %s\n", encrypted_message);
    printf("Decrypting message...\n");
    char* decrypted_message = decrypt(encrypted_message, key);
 
    printf("Decrypted message: %s\n", decrypted_message);
    free(key);
    free(encrypted_message);
    free(decrypted_message);
    return 0;
}
 
char* encrypt(char* message, char* keygen) {
    int key_length = strlen(keygen);
    int message_length = strlen(message);
    char* encrypted_message = (char*) malloc(message_length * sizeof(char));
 
    for(int i = 0; i < message_length - 1; i++) {
        if(message[i] == ' ') {
            encrypted_message[i] = ' ';
        }
        else {
            encrypted_message[i] = ((message[i] - 'a' + keygen[i % key_length] - 'a') % 26) + 'a';
        }
    }
    encrypted_message[message_length - 1] = '\0';
    return encrypted_message;
}
 
char* decrypt(char* message, char* key) {
    int key_length = strlen(key);
    int message_length = strlen(message);
    char* decrypted_message = (char*) malloc(message_length * sizeof(char));
 
    for(int i = 0; i < message_length - 1; i++) {
        if(message[i] == ' ') {
            decrypted_message[i] = ' ';
        }
        else {
            decrypted_message[i] = ((message[i] - 'a' - key[i % key_length] + 'a' + 26) % 26) + 'a';
        }
    }
    decrypted_message[message_length - 1] = '\0';
    return decrypted_message;
}
 
char* generate_key(int length) {
    time_t t;
    srand((unsigned) time(&t));
    char* key = (char*) malloc(length * sizeof(char));
    for(int i = 0; i < length; i++) {
        key[i] = (rand() % 26) + 'a'; // Generate a random lowercase letter
    }
    key[length] = '\0';
    return key;
}