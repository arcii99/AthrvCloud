//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Ada Lovelace
#include<stdio.h>
#include<string.h>

void encrypt(char str[], int key);

int main(){
    char message[100];
    int key;

    printf("Enter the message to be encrypted: ");
    fgets(message, 100, stdin);

    printf("Enter the key: ");
    scanf("%d", &key);

    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    return 0;
}

void encrypt(char str[], int key){
    int i;
    
    for(i = 0; i < strlen(str); i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] = 'a' + (str[i] - 'a' + key) % 26;   //Encryption formula for lowercase letters
        }
        else if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = 'A' + (str[i] - 'A' + key) % 26;   //Encryption formula for uppercase letters
        }
    }
}