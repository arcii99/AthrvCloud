//FormAI DATASET v1.0 Category: Encryption ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void encrypt(char* data, char* key) {
    int data_len = strlen(data);
    int key_len = strlen(key);
    int count = 0;
    for(int i = 0; i < data_len; i++) {
        data[i] = data[i] ^ key[count];
        count++;
        if(count == key_len) {
            count = 0;
        }
    }
}

int main() {
    // Generate random seed for key creation
    srand(time(NULL));
    // Define character set for key creation
    char charset[63] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // Define maximum key length
    int max_key_len = 128;
    // Get user input for data to encrypt
    printf("Enter data to encrypt: ");
    char data[1024];
    scanf("%[^\n]", data);
    getchar();
    // Generate random key of random length within max key length
    int key_len = rand() % max_key_len + 1;
    char key[key_len];
    for(int i = 0; i < key_len; i++) {
        key[i] = charset[rand() % 63];
    }
    // Encrypt data with generated key
    encrypt(data, key);
    // Print encrypted data and key
    printf("Encrypted data: %s\n", data);
    printf("Key: %s\n", key);
    return 0;
}