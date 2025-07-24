//FormAI DATASET v1.0 Category: Encryption ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *input, char *output, char *key){
    int i = 0;
    int key_len = strlen(key);
    
    while(input[i] != '\0'){
        output[i] = input[i] ^ key[i % key_len];
        i++;
    }
    output[i] = '\0';
}

void decrypt(char *input, char *output, char *key){
    encrypt(input, output, key);
}

int main(){

    char input[50];
    char output[50];
    char key[25];

    printf("Welcome to the Happy Encryption Program!\n\n");
    printf("Please enter a string that is no more than 50 characters: ");
    fgets(input, 50, stdin);

    printf("\nPlease enter a key that is no more than 25 characters: ");
    fgets(key, 25, stdin);

    //Remove newline characters
    input[strcspn(input, "\n")] = 0;
    key[strcspn(key, "\n")] = 0;

    encrypt(input, output, key);

    printf("\nYour encrypted message is: %s\n", output);

    decrypt(output, input, key);

    printf("\nYour decrypted message is: %s\n", input);

    return 0;
}