//FormAI DATASET v1.0 Category: Modern Encryption ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// function to encrypt the message
void encrypt(char *message, int key){
    int i;
    for(i = 0; i < strlen(message); i++){
        message[i] = message[i] + key%26; // adding the key offset
        if (message[i] > 'z')  // wraparound
            message[i] = message[i] - 26;
    }
}

// function to decrypt the message
void decrypt(char *message, int key){
    int i;
    for(i = 0; i < strlen(message); i++){
        message[i] = message[i] - key%26; // subtracting the key offset
        if (message[i] < 'a')  // wraparound
            message[i] = message[i] + 26;
    }
}

int main(){
    char message[100];
    int key, choice;
    printf("Please enter a message to encrypt (max 100 characters): ");
    fgets(message, 100, stdin);
    printf("Please enter a key (an integer value): ");
    scanf("%d", &key);
    printf("\nPlease choose an option:\n1. Encrypt the message\n2. Decrypt the message\n");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            encrypt(message, key);
            printf("\nEncrypted message: %s", message);
            break;
        case 2:
            decrypt(message, key);
            printf("\nDecrypted message: %s", message);
            break;
        default:
            printf("\nInvalid choice!");
    }
    return 0;
}