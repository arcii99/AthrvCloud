//FormAI DATASET v1.0 Category: Modern Encryption ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* message, int key){
    int i;
    for(i=0; message[i]!= '\0'; i++){
        if(message[i]>= 'A' && message[i]<= 'Z'){
            message[i] = ((message[i] - 'A' + key)%26) + 'A';
        }
        else if(message[i] >= 'a' && message[i] <= 'z'){
            message[i] = ((message[i] - 'a' + key)%26) + 'a';
        }
    }
}

void decrypt(char* message, int key){
    int i;
    for(i=0; message[i]!='\0'; i++){
        if(message[i]>='A' && message[i]<='Z'){
            message[i]=((message[i]-'A'-key+26)%26)+'A';
        }
        else if(message[i]>='a'&&message[i]<='z'){
            message[i]=((message[i]-'a'-key+26)%26)+'a';
        }
    }    
}

int main(){

    char message[100];
    int key;

    printf("Enter the message to be encrypted: ");
    scanf("%[^\n]s", message);

    printf("Enter the key: ");
    scanf("%d", &key);

    encrypt(message, key);
    printf("\nEncrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s", message);

    return 0;
}