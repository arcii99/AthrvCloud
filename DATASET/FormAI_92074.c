//FormAI DATASET v1.0 Category: Encryption ; Style: content
#include<stdio.h>
#include<string.h>

void encrypt(char message[], int key){
    int i;
    char encryptedMessage[strlen(message) + 1];
    for(i = 0; message[i] != '\0'; i++){
        if(message[i] >= 'a' && message[i] <= 'z') {
            encryptedMessage[i] = (((message[i] - 'a') + key) % 26) + 'a'; //Caesar cipher
        }
        else if(message[i] >= 'A' && message[i] <= 'Z') {
            encryptedMessage[i] = (((message[i] - 'A') + key) % 26) + 'A';
        }
        else {
            encryptedMessage[i] = message[i];
        }
    }
    encryptedMessage[i] = '\0';

    printf("Encrypted message: %s\n", encryptedMessage);
}

int main(){
    char message[100];
    int key;

    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);

    printf("Enter encryption key: ");
    scanf("%d", &key);

    encrypt(message, key);

    return 0;
}