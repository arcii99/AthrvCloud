//FormAI DATASET v1.0 Category: Encryption ; Style: scientific
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isUpperCase(char c);
bool isLowerCase(char c);
void encrypt(char *str, int key);

bool isUpperCase(char c){
    return (c >= 'A' && c <= 'Z');
}

bool isLowerCase(char c){
    return (c >= 'a' && c <= 'z');
}

void encrypt(char *str, int key){
    int i;
    for(i = 0; i < strlen(str); i++){
        char c = str[i];
        if(isUpperCase(c)){
            str[i] = ((c - 'A' + key) % 26) + 'A';
        }
        else if(isLowerCase(c)){
            str[i] = ((c - 'a' + key) % 26) + 'a';
        }
    }
}

int main(){
    char str[50];
    int key;
    printf("Enter string to encrypt: ");
    fgets(str, sizeof(str), stdin);
    printf("Enter encryption key (1-25): ");
    scanf("%d", &key);
    encrypt(str, key);
    printf("Encrypted string: %s", str);
    return 0;
}