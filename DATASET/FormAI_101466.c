//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_MESSAGE_SIZE 1000
#define MAX_KEY_SIZE 1000

void encrypt(char* message, char* key){
    int message_length = strlen(message);
    int i;
    for(i = 0; i < message_length; i++){
        message[i] = message[i] ^ key[i % strlen(key)];
    }
}

void decrypt(char* message, char* key){
    encrypt(message, key);
}

int main(){
    char message[MAX_MESSAGE_SIZE];
    char key[MAX_KEY_SIZE];

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0;

    printf("Enter a key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = 0;

    srand(time(NULL));
    int random_index = rand() % strlen(message);
    message[random_index] = message[random_index] ^ 1;

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}