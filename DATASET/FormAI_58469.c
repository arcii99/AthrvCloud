//FormAI DATASET v1.0 Category: Encryption ; Style: recursive
#include<stdio.h>
#include<string.h>

void encrypt(char* s, int len){
    // Base case
    if(len==0){
        return;
    }
    // Recursive call
    encrypt(s+1, len-1);
    // Encryption logic
    if((*s >= 'a' && *s < 'z') || (*s >= 'A' && *s < 'Z')){
        *s = *s + 1;
    }
    else if(*s == 'z' || *s == 'Z'){
        *s = *s - 25;
    }
}

int main(){
    char str[100];
    printf("Enter a string to encrypt: ");
    fgets(str, 100, stdin);
    int len = strlen(str);
    // Removing newline character from string
    if(str[len-1] == '\n'){
        str[len-1] = '\0';
        len--;
    }
    encrypt(str, len);
    printf("Encrypted string: %s", str);
    return 0;
}