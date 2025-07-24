//FormAI DATASET v1.0 Category: Modern Encryption ; Style: mind-bending
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* encrypt(char* message, char* key){
    char* result = malloc(sizeof(char)*strlen(message));

    for(int i = 0; i < strlen(message); i++){
        result[i] = message[i] ^ key[i % strlen(key)];
    }

    return result;
}

char* decrypt(char* message, char* key){
    char* result = malloc(sizeof(char)*strlen(message));

    for(int i = 0; i < strlen(message); i++){
        result[i] = message[i] ^ key[i % strlen(key)];
    }

    return result;
}

int main(){
    char message[] = "The quick brown fox jumps over the lazy dog.";
    char key[] = "encryption";

    char* encrypted_message = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted_message);

    char* decrypted_message = decrypt(encrypted_message, key);
    printf("Decrypted message: %s\n", decrypted_message);

    free(encrypted_message);
    free(decrypted_message);

    return 0;
}