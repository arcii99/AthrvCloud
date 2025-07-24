//FormAI DATASET v1.0 Category: Encryption ; Style: happy
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>

void encrypt(char *message, int key) {
    int i;
    char ch;
    for(i = 0; message[i] != '\0'; i++) {
        ch = message[i];
        if(ch >= 'a' && ch <= 'z') {
            ch = ch + key;
            if(ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }
            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z') {
            ch = ch + key;
            if(ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }
            message[i] = ch;
        }
    }
}

void decrypt(char *message, int key) {
    int i;
    char ch;
    for(i = 0; message[i] != '\0'; i++) {
        ch = message[i];
        if(ch >= 'a' && ch <= 'z') {
            ch = ch - key;
            if(ch < 'a') {
                ch = ch + 'z' - 'a' + 1;
            }
            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z') {
            ch = ch - key;
            if(ch < 'A') {
                ch = ch + 'Z' - 'A' + 1;
            }
            message[i] = ch;
        }
    }
}

int main() {
    char message[100], enc_message[100], dec_message[100];
    int key;
    srand(time(NULL));
    key = rand() % 26 + 1;
    
    printf("Welcome to Happy Encryption!\n");
    printf("Please enter your message to be encrypted: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\r\n")] = 0; // Remove trailing newline character
    
    encrypt(message, key);
    printf("\nYour encrypted message: %s\n", message);
    
    decrypt(message, key);
    printf("\nYour decrypted message: %s\n", message);
    
    printf("\nThank you for using Happy Encryption! Have a nice day!\n");
    return 0;
}