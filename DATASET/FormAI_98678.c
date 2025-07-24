//FormAI DATASET v1.0 Category: Modern Encryption ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *message, char *key) {
    int message_len = strlen(message);
    int key_len = strlen(key);
    
    // Generate the new key
    char new_key[message_len];
    int j = 0;
    
    for(int i = 0; i < message_len; i++) {
        new_key[i] = key[j];
        j++;
        if(j == key_len) {
            j = 0;
        }
    }

    // Perform the encryption
    char encrypted_message[message_len+1];
    for(int i = 0; i < message_len; i++) {
        encrypted_message[i] = ((message[i]-'a') + (new_key[i]-'a')) % 26 + 'a';
    }
    encrypted_message[message_len] = '\0';
    
    printf("Encrypted Message: %s\n", encrypted_message);
}

int main() {
    char message[] = "helloworld";
    char key[] = "secretkey";
    
    encrypt(message, key);
    
    return 0;
}