//FormAI DATASET v1.0 Category: Modern Encryption ; Style: expert-level
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

//Make sure the key is different for each session
int key = 12345;

//Function to encrypt a given message using the key
void encrypt(char *message, int key){
    int i;
    srand(key);
    for(i=0;i<strlen(message);i++){
        message[i] = message[i] + (rand()%10);
    }
}

//Function to decrypt a given message using the key
void decrypt(char *message, int key){
    int i;
    srand(key);
    for(i=0;i<strlen(message);i++){
        message[i] = message[i] - (rand()%10);
    }
}

//Main function to demonstrate the encryption and decryption process
int main(){
    char message[100];
    printf("Enter the message to be encrypted: ");
    scanf("%[^\n]s",message);
    encrypt(message,key);
    printf("Encrypted Message: %s\n",message);
    decrypt(message,key);
    printf("Decrypted Message: %s\n",message);
    return 0;
}