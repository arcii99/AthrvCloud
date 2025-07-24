//FormAI DATASET v1.0 Category: Encryption ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

char* encrypt(char* message, char* key) {
    int message_len = strlen(message);
    int key_len = strlen(key);
    char* result = (char*) malloc(message_len*sizeof(char));
    for(int i = 0; i < message_len; i++) {
        result[i] = message[i] ^ key[i % key_len];
    }
    return result;
}

int main() {
    char* message = "Claude Shannon";
    char* key = "Encryption";
    char* encrypted_message = encrypt(message, key);
    printf("Encrypted message : %s\n", encrypted_message);
    char* decrypted_message = encrypt(encrypted_message, key);
    printf("Decrypted message : %s\n", decrypted_message);
    return 0;
}