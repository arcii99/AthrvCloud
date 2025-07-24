//FormAI DATASET v1.0 Category: modern Encryption ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to perform encryption
void encrypt(char *str, int key){
    int i;
    for(i=0;i<strlen(str);i++){
        if(str[i]>='a' && str[i]<='z'){
            str[i] = (char)(((int)str[i] + key - 97) % 26 + 97); //Encryption formula
        }
        else if(str[i]>='A' && str[i]<='Z'){
            str[i] = (char)(((int)str[i] + key - 65) % 26 + 65); //Encryption formula
        }
    }
}

int main(){
    char str[1000];
    int key;
    printf("Enter string to encrypt: ");
    fgets(str,1000,stdin);
    printf("Enter key: ");
    scanf("%d",&key);
    encrypt(str,key);
    printf("Encrypted string: %s",str);
    return 0;
}