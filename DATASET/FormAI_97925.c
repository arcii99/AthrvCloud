//FormAI DATASET v1.0 Category: modern Encryption ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void bit_swap(char* input){
    int len = strlen(input);
    for(int i=0;i<len;i++){
        if(input[i] == '0') input[i] = '1';
        else input[i] = '0';
    }
}

void hex_swap(char* input){
    int len = strlen(input);
    for(int i=0;i<len;i++){
        if(input[i]>='a' && input[i]<='f') input[i] = '9'-(input[i]-'a');
        if(input[i]>='A' && input[i]<='F') input[i] = '9'-(input[i]-'A');
    }
}

void encrypt(char* input, char* key){
    bit_swap(input);
    hex_swap(key);
    strcat(input,key);
}

void decrypt(char* input, char* key){
    int len = strlen(key);
    char temp[len+1];
    strcpy(temp,key);
    bit_swap(input);
    hex_swap(temp);
    if(strstr(input,temp)){
        int index = strlen(input)-len;
        input[index] = '\0';
    }
}

int main(){
    char message[] = "Hello World";
    char key[] = "c0ffee";
    printf("Original Message: %s\n", message);
    encrypt(message, key);
    printf("Encrypted Message: %s\n", message);
    decrypt(message, key);
    printf("Decrypted Message: %s\n", message);
    return 0;
}