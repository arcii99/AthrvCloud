//FormAI DATASET v1.0 Category: Modern Encryption ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SECRET_KEY 3

void encrypt(char* string){
    int len = strlen(string);
    for(int i=0; i<len; i++){
        if(string[i]>='a' && string[i]<='z'){ 
            string[i] = ((string[i]-'a')+SECRET_KEY)%26 + 'a'; 
        }
        else if(string[i]>='A' && string[i]<='Z'){ 
            string[i] = ((string[i]-'A')+SECRET_KEY)%26 + 'A'; 
        }
        else{ 
            // Do nothing 
        }
    }
}

void decrypt(char* string){
    int len = strlen(string);
    for(int i=0; i<len; i++){
        if(string[i]>='a' && string[i]<='z'){
            string[i] = ((string[i]-'a')-SECRET_KEY+26)%26 + 'a';
        }
        else if(string[i]>='A' && string[i]<='Z'){
            string[i] = ((string[i]-'A')-SECRET_KEY+26)%26 + 'A';
        }
        else{
            // Do nothing
        }
    }
}

int main(){
    char original[] = "Hello World! 123";
    printf("%s\n",original);
    encrypt(original);
    printf("%s\n",original);
    decrypt(original);
    printf("%s\n",original);
    return 0;
}