//FormAI DATASET v1.0 Category: Modern Encryption ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

char* encrypt(char* message, char* key){
    int key_length = strlen(key);
    int message_length = strlen(message);
    char* encrypted = malloc((message_length + 1) * sizeof(char));
    int i;
    for(i = 0; i < message_length; i++){
        encrypted[i] = message[i] ^ key[i % key_length];
    }
    encrypted[i] = '\0';
    return encrypted;
}

char* decrypt(char* message, char* key){
    int key_length = strlen(key);
    int message_length = strlen(message);
    char* decrypted = malloc((message_length + 1) * sizeof(char));
    int i;
    for(i = 0; i < message_length; i++){
        decrypted[i] = message[i] ^ key[i % key_length];
    }
    decrypted[i] = '\0';
    return decrypted;
}

int main(){
    char* message = "Hello, world!";
    char* key = "secret";
    char* encrypted = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted);
    char* decrypted = decrypt(encrypted, key);
    printf("Decrypted message: %s\n", decrypted);
    free(encrypted);
    free(decrypted);
    return 0;
}