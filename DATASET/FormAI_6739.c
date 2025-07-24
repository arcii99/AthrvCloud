//FormAI DATASET v1.0 Category: Encryption ; Style: Dennis Ritchie
#include<stdio.h>
#include<string.h>

void encrypt(char* plaintext, int key);

int main(){
    char plaintext[100];
    int key;

    printf("Enter the plaintext to encrypt: ");
    scanf("%s", plaintext);

    printf("Enter the key for encryption (0-25): ");
    scanf("%d", &key);

    encrypt(plaintext, key);

    printf("Encrypted text: %s\n", plaintext);

    return 0;
}

void encrypt(char* plaintext, int key){
    int len = strlen(plaintext);
    int i;

    for(i = 0; i < len; i++){
        if(plaintext[i] >= 'a' && plaintext[i] <= 'z'){
            plaintext[i] = 'a' + ((plaintext[i] - 'a' + key) % 26);
        }
        else if(plaintext[i] >= 'A' && plaintext[i] <= 'Z'){
            plaintext[i] = 'A' + ((plaintext[i] - 'A' + key) % 26);
        }
    }
}