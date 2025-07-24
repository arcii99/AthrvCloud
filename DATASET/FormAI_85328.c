//FormAI DATASET v1.0 Category: Encryption ; Style: energetic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void encrypt(char *str, int key){
    int i;
    for(i=0;i<strlen(str);i++){
        str[i] = str[i] ^ key;
    }
}

void decrypt(char *str, int key){
    int i;
    for(i=0;i<strlen(str);i++){
        str[i] = str[i] ^ key;
    }
}

int main(){

    char s[256];
    int key = 5;
    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);
    
    printf("Original string: %s", s);
    encrypt(s, key);
    printf("Encrypted string: %s", s);
    
    decrypt(s, key);
    printf("Decrypted string: %s", s);

    return 0;
    
}