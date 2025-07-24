//FormAI DATASET v1.0 Category: Modern Encryption ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STR_LEN 100

void generate_key(char *key, int len);
void encrypt(char *msg, char *key);
void decrypt(char *msg, char *key);

int main() {
    char msg[MAX_STR_LEN];
    char key[MAX_STR_LEN];
    
    // Get message from user
    printf("Enter message to encrypt: ");
    fgets(msg, MAX_STR_LEN, stdin);
    msg[strcspn(msg, "\n")] = '\0';
    
    // Generate key
    srand(time(0));
    generate_key(key, strlen(msg));
    
    // Encrypt message
    encrypt(msg, key);
    printf("Encrypted message: %s\n", msg);
    
    // Decrypt message
    decrypt(msg, key);
    printf("Decrypted message: %s\n", msg);
    
    return 0;
}

void generate_key(char *key, int len) {
    int i;
    for(i = 0; i < len; i++) {
        key[i] = rand() % 26 + 'A'; // Generate random capital letter
    }
    key[i] = '\0';
}

void encrypt(char *msg, char *key) {
    int i;
    for(i = 0; msg[i] != '\0'; i++) {
        // Shift letter in message by corresponding letter in key
        int shift = key[i] - 'A';
        if(msg[i] + shift > 'Z') {
            msg[i] = 'A' + (msg[i] + shift - 'Z' - 1);
        } else {
            msg[i] += shift;
        }
    }
}

void decrypt(char *msg, char *key) {
    int i;
    for(i = 0; msg[i] != '\0'; i++) {
        // Shift letter in message back by corresponding letter in key
        int shift = key[i] - 'A';
        if(msg[i] - shift < 'A') {
            msg[i] = 'Z' - ('A' - (msg[i] - shift) - 1);
        } else {
            msg[i] -= shift;
        }
    }
}