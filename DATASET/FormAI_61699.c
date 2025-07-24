//FormAI DATASET v1.0 Category: Modern Encryption ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define KEY_SIZE 8

// Function to generate random key
void generateKey(char *key){
    int i;
    srand(time(NULL)); // Seed for random number generator
    for(i=0;i<KEY_SIZE;i++){
        // Generating random uppercase letters
        key[i] = rand()%26 + 'A';
    }
    key[i] = '\0'; // Adding null terminator
}

// Function to perform encryption of message using key
void encrypt(char *message, char *key){
    int i;
    for(i=0;message[i]!='\0';i++){
        // Performing XOR operation with key
        message[i] = message[i] ^ key[i%KEY_SIZE];
    }
}

int main(){
    char message[100], key[KEY_SIZE+1];
    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);
    generateKey(key);
    printf("Generated key: %s\n", key);
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);
    return 0;
}