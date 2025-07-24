//FormAI DATASET v1.0 Category: modern Encryption ; Style: synchronous
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

void encrypt(char* msg, int key);
void decrypt(char* msg, int key);

int main() {
    char message[MAX_SIZE];
    int key;
    
    printf("Enter message to be encrypted: ");
    fgets(message, MAX_SIZE, stdin);
    
    printf("Enter encryption key: ");
    scanf("%d", &key);
    
    encrypt(message, key);
    printf("\nEncrypted message: %s", message);
    
    decrypt(message, key);
    printf("Decrypted message: %s", message);
    
    return 0;
}

void encrypt(char* msg, int key) {
    int i;
    char ch;
    
    for(i = 0; i < strlen(msg); i++) {
        ch = msg[i];
        
        if(ch >= 'a' && ch <= 'z') {
            ch = ch + key;
            
            if(ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }
            
            msg[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z') {
            ch = ch + key;
            
            if(ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }
            
            msg[i] = ch;
        }
    }
}

void decrypt(char* msg, int key) {
    int i;
    char ch;
    
    for(i = 0; i < strlen(msg); i++) {
        ch = msg[i];
        
        if(ch >= 'a' && ch <= 'z') {
            ch = ch - key;
            
            if(ch < 'a') {
                ch = ch + 'z' - 'a' + 1;
            }
            
            msg[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z') {
            ch = ch - key;
            
            if(ch < 'A') {
                ch = ch + 'Z' - 'A' + 1;
            }
            
            msg[i] = ch;
        }
    }
}