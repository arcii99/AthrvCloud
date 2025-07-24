//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void encrypt(char* message, int key) {
    for(int i=0;message[i]!='\0';++i) {
        if(message[i]>='a' && message[i]<='z') {
            message[i] = ((message[i] - 'a' + key)%26) + 'a'; //Shift by key
        }
        else if(message[i]>='A' && message[i]<='Z') {
            message[i] = ((message[i] - 'A' + key)%26) + 'A';
        }
    }
}

void decrypt(char* message, int key) {
    for(int i=0;message[i]!='\0';++i) {
        if(message[i]>='a' && message[i]<='z') {
            message[i] = ((message[i] - 'a' - key +26)%26) + 'a'; //Shift back by key
        }
        else if(message[i]>='A' && message[i]<='Z') {
            message[i] = ((message[i] - 'A' - key +26)%26) + 'A';
        }
    }
}

int main() {
    char message[500]; 
    int key; 

    printf("Enter a message: ");
    fgets(message, 500, stdin);

    printf("Enter a key: ");
    scanf("%d", &key);

    printf("Original message: %s", message);

    encrypt(message, key);
    printf("Encrypted message: %s", message);

    decrypt(message, key);
    printf("Decrypted message: %s", message);
    
    return 0;
}