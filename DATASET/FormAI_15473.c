//FormAI DATASET v1.0 Category: Encryption ; Style: shocked
#include <stdio.h>
#include <string.h>

void encrypt(char *message, int key){
    int i = 0;
    while(message[i] != '\0'){
        message[i] = message[i] + key;
        i++;
    }
}

void decrypt(char *message, int key){
    int i = 0;
    while(message[i] != '\0'){
        message[i] = message[i] - key;
        i++;
    }
}

int main(){
    char message[100];
    int key;

    printf("Enter message to encrypt: ");
    scanf("%s", message);

    printf("Enter a key: ");
    scanf("%d", &key);

    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    decrypt(message, key);

    printf("Decrypted message: %s\n", message);

    return 0;
}