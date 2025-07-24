//FormAI DATASET v1.0 Category: Encryption ; Style: recursive
#include <stdio.h>

void encrypt(char *message, int key){
    if (*message == '\0'){
        return;
    }
    else{
        *message = ((*message + key) % 26) + 'A';
        encrypt(message + 1, key);
    }
}

void decrypt(char *message, int key){
    if (*message == '\0'){
        return;
    }
    else{
        *message = ((*message - key + 26) % 26) + 'A';
        decrypt(message + 1, key);
    }
}

int main(){
    char message[100];
    int key;
    
    printf("Enter a message to encrypt: ");
    scanf("%[^\n]s", message);
    printf("Enter a key value (1-25): ");
    scanf("%d", &key);
    
    encrypt(message, key);
    
    printf("Encrypted message: %s\n", message);
    
    decrypt(message, key);
    
    printf("Decrypted message: %s\n", message);
    
    return 0;
}