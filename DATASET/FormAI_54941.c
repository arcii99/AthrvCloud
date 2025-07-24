//FormAI DATASET v1.0 Category: Encryption ; Style: authentic
#include<stdio.h>
#include<string.h>

void encrypt(char *str, int key){
    int len = strlen(str);
    for(int i=0;i<len;i++){
        int ascii = (int)str[i];
        ascii = ascii + key;
        str[i] = (char)ascii;
    }
}

void decrypt(char *str, int key){
    int len = strlen(str);
    for(int i=0;i<len;i++){
        int ascii = (int)str[i];
        ascii = ascii - key;
        str[i] = (char)ascii;
    }
}

int main(){
    char message[100];
    int key;
    printf("Enter the message to be encrypted:\n");
    fgets(message,sizeof(message),stdin);
    printf("Enter the key:\n");
    scanf("%d",&key);
    encrypt(message,key);
    printf("Encrypted message: %s\n",message);
    printf("\nDecrypting the message...\n\n");
    decrypt(message,key);
    printf("Decrypted message: %s\n",message);
    return 0;
}