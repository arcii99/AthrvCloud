//FormAI DATASET v1.0 Category: modern Encryption ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ENCRYPTION_KEY 37
#define MAX_MESSAGE_LENGTH 100

void encrypt(char* message, int key){
    for (int i = 0; i < strlen(message); i++){
        message[i] = message[i] + key;
    }
}

void decrypt(char* message, int key){
    for (int i = 0; i < strlen(message); i++){
        message[i] = message[i] - key;
    }
}

int main(){

    char message[MAX_MESSAGE_LENGTH];
    int key, choice;

    printf("Enter the message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    srand(time(0)); //initialize random seed
    key = rand() % 100; //generate random number between 0 and 99

    encrypt(message, ENCRYPTION_KEY);
    printf("\nEncrypted message: %s\n", message);

    printf("\nDo you want to decrypt the message? Enter 1 for yes, 0 for no: ");
    scanf("%d", &choice);

    if (choice == 1){
        decrypt(message, key);
        printf("\nDecrypted message: %s\n", message);
    }

    return 0;
}