//FormAI DATASET v1.0 Category: Encryption ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void encrypt(char *message, int key){
    while(*message){
        *message = (*message) + key;
        message++;
    }
}

void decrypt(char *message, int key){
    while(*message){
        *message = (*message) - key;
        message++;
    }
}

int main(){
    char message[100], enc_message[100], dec_message[100];
    int key;

    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);
    message[strcspn(message, "\n")] = 0;

    printf("Enter a key: ");
    scanf("%d", &key);

    strcpy(enc_message, message);
    encrypt(enc_message, key);

    printf("Encrypted message: %s\n", enc_message);

    strcpy(dec_message, enc_message);
    decrypt(dec_message, key);

    printf("Decrypted message: %s\n", dec_message);

    return 0;
}