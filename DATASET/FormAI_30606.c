//FormAI DATASET v1.0 Category: Modern Encryption ; Style: real-life
#include<stdio.h>
#include<string.h>

void encrypt(char msg[], int key){
    int i;
    for(i=0; i<strlen(msg); i++){
        msg[i] += key;
    }
}

void decrypt(char msg[], int key){
    int i;
    for(i=0; i<strlen(msg); i++){
        msg[i] -= key;
    }
}

int main(){
    int key = 10; // set encryption key
    char msg[100]; // maximum length of message set to 100
    
    printf("Enter your message: ");
    fgets(msg, 100, stdin); // read input string from user
    
    // encrypt the message
    encrypt(msg, key);
    printf("Encrypted message: %s\n", msg);

    // decrypt the message
    decrypt(msg, key);
    printf("Decrypted message: %s\n", msg);
    
    return 0;
}