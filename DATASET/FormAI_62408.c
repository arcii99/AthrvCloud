//FormAI DATASET v1.0 Category: Encryption ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void encrypt(char *key, char *message){
    int len_key = strlen(key);
    int len_msg = strlen(message);

    for(int i=0,j=0; i<len_msg; i++,j++){
        if(j>=len_key) j=0;
        message[i] = ((toupper(key[j])-'A'+message[i]-'A')%26)+'A';
    }
}

void decrypt(char *key, char *message){
    int len_key = strlen(key);
    int len_msg = strlen(message);

    for(int i=0,j=0; i<len_msg; i++,j++){
        if(j>=len_key) j=0;
        message[i] = ((message[i]+26-toupper(key[j]))%26)+'A';
    }
}

int main(){
    char key[100], message[100];

    printf("Enter key: ");
    fgets(key, 100, stdin);
    key[strcspn(key, "\n")] = 0; // remove newline character from input

    printf("Enter message: ");
    fgets(message, 100, stdin);
    message[strcspn(message, "\n")] = 0; // remove newline character from input

    encrypt(key, message);
    printf("Encrypted message: %s\n", message);

    decrypt(key, message);
    printf("Decrypted message: %s\n", message);

    return 0;
}