//FormAI DATASET v1.0 Category: Encryption ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100 //maximum size of input string

char* encrypt(char* str, int key){
    int len = strlen(str);
    char* encrypted = (char*)malloc(sizeof(char) * (len + 1)); //memory allocation for encrypted string
    strcpy(encrypted, str); //copying input string to encrypted string
    
    for(int i=0; encrypted[i]!='\0'; i++){
        if(encrypted[i] >= 'a' && encrypted[i] <= 'z'){ //encrypt lowercase letters
            encrypted[i] = (encrypted[i] - 'a' + key) % 26 + 'a';
        }
        else if(encrypted[i] >= 'A' && encrypted[i] <= 'Z'){ //encrypt uppercase letters
            encrypted[i] = (encrypted[i] - 'A' + key) % 26 + 'A';
        }
    }
    return encrypted;
}

int main(){
    char input[MAX_SIZE]; //input string
    int key; //encryption key
    
    printf("Enter the string to be encrypted:\n");
    fgets(input, MAX_SIZE, stdin);
    input[strcspn(input, "\n")] = '\0'; //removing newline character from input string
    
    printf("Enter the encryption key (0 to 25):\n");
    scanf("%d", &key);
    
    if(key < 0 || key > 25){ //invalid key
        printf("Invalid encryption key!\n");
        return 0;
    }
    
    char* encrypted = encrypt(input, key); //encrypting input string
    printf("Encrypted string: %s\n", encrypted);
    
    free(encrypted); //freeing memory allocated for encrypted string
    return 0;
}