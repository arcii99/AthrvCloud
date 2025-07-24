//FormAI DATASET v1.0 Category: Encryption ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Function that takes in a string and its length and performs an encryption with a generated key*/
void encrypt(char *string, int stringLength){
    char key[stringLength];
    int i, j;

    for(i = 0; i < stringLength; i++){
        key[i] = (char)(((double)rand()/RAND_MAX)*256); //Generate a random key
    }

    for(i = 0; i < stringLength; i++){
        string[i] = string[i]^key[i%stringLength]; //Perform the XOR encryption
    }

    printf("Encrypted string: %s\n", string);
    printf("Key: %s\n", key);
}

int main(){
    char plaintext[100];
    int plaintextLength;

    printf("Enter the plaintext: ");
    gets(plaintext);

    plaintextLength = strlen(plaintext);

    encrypt(plaintext, plaintextLength);

    return 0;
}