//FormAI DATASET v1.0 Category: File Encyptor ; Style: lively
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

void encrypt(char* input, int key){
    int len = strlen(input);
    for(int i=0;i<len;i++){
        input[i]=input[i]+key;
    }
}

void decrypt(char* input, int key){
    int len = strlen(input);
    for(int i=0;i<len;i++){
        input[i]=input[i]-key;
    }
}

int main(){

    char message[MAX_LENGTH];
    int key, len;

    printf("Enter the message that you want to encrypt: ");
    fgets(message, MAX_LENGTH, stdin);

    printf("Enter the key: ");
    scanf("%d", &key);

    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    decrypt(message, key);

    printf("Decrypted message: %s\n", message);

    return 0;
}