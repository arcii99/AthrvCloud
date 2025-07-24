//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//key for the encryption
#define KEY "touring123"

//function to encrypt the message
void encrypt(char *msg){
    int msglen = strlen(msg);
    int keylen = strlen(KEY);
    int i, j;

    //loop through all the characters in the message
    for(i=0, j=0; i<msglen; i++, j++){
        //if we reach the end of the key, restart from the beginning
        if(j == keylen){
            j = 0;
        }

        //perform the encryption using XOR operation
        msg[i] = msg[i] ^ KEY[j];
    }
}

int main(){
    char message[100];
    printf("Enter a message to encrypt: ");
    scanf("%[^\n]", message);

    //encrypt the message
    encrypt(message);

     printf("Encrypted message: %s\n", message);

    return 0;
}