//FormAI DATASET v1.0 Category: Encryption ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char message[100], key[100], encrypted[100], decrypted[100];
    int i,j,k,length,choice;
    
    printf("Enter the message to be encrypted: ");
    fgets(message, 100, stdin);
    printf("Enter the key: ");
    fgets(key, 100, stdin);
    
    length = strlen(message);
    
    //Encryption Process
    for(i=0,j=0;i<length;i++,j++){
        if(j == strlen(key)){
            j = 0;
        }
        encrypted[i] = (message[i] + key[j]) % 26 + 'A';
    }
    encrypted[length] = '\0';
    
    printf("\nEncrypted Message: %s", encrypted);
    
    //Decryption Process
    for(i=0,j=0;i<length;i++,j++){
        if(j == strlen(key)){
            j = 0;
        }
        decrypted[i] = (encrypted[i] - key[j] + 26) % 26 + 'A';
    }
    decrypted[length] = '\0';
    
    printf("\nDecrypted Message: %s", decrypted);
    
    return 0;
}