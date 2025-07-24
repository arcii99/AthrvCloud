//FormAI DATASET v1.0 Category: Encryption ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void encrypt(char *message, int key){
    int len = strlen(message);
    char *encrypted_message = (char*)malloc(sizeof(char)*(len+1));
    for(int i=0;i<len;i++){
        if(message[i]>='a'&&message[i]<='z'){
            encrypted_message[i] = (((message[i] - 'a') + key)%26)+'a';
        }
        else if(message[i]>='A'&&message[i]<='Z'){
            encrypted_message[i] = (((message[i] - 'A') + key)%26)+'A';
        }
        else{
            encrypted_message[i] = message[i];
        }
    }
    encrypted_message[len]='\0';
    printf("Encrypted Message: %s\n",encrypted_message);
}

int main(){
    printf("Enter the text to be encrypted: ");
    char *message = (char*)malloc(sizeof(char)*500);
    scanf("%[^\n]%*c", message);
    printf("Enter the encryption key: ");
    int key;
    scanf("%d", &key);
    encrypt(message,key);
    free(message);
    message = NULL;
    return 0;
}