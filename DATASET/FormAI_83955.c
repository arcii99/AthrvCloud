//FormAI DATASET v1.0 Category: Modern Encryption ; Style: relaxed
#include<stdio.h>
#include<string.h>

void encrypt(char* message, int key){
    int len = strlen(message);
    for(int i=0; i<len; i++){
        if(message[i]>='A' && message[i]<='Z'){
            message[i] = ((message[i]+key-65)%26)+65;
        }
        else if(message[i]>='a' && message[i]<='z'){
            message[i] = ((message[i]+key-97)%26)+97;
        }
    }
}

void decrypt(char* message, int key){
    int len = strlen(message);
    int x;
    for(int i=0; i<len; i++){
        if(message[i]>='A' && message[i]<='Z'){
            x = (message[i]-key-65);
            if(x<0){
                x = x+26;
            }
            message[i] = x+65;
        }
        else if(message[i]>='a' && message[i]<='z'){
            x = (message[i]-key-97);
            if(x<0){
                x = x+26;
            }
            message[i] = x+97;
        }
    }
}

int main(){
    char message[100];
    int key;
    printf("Enter message: ");
    scanf("%[^\n]", message); //Input string with spaces
    printf("Enter key (1-25): ");
    scanf("%d", &key);
    encrypt(message, key);
    printf("\nEncrypted message: %s\n", message);
    decrypt(message, key);
    printf("\nDecrypted message: %s\n", message);
    return 0;
}