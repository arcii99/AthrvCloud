//FormAI DATASET v1.0 Category: Encryption ; Style: lively
#include<stdio.h>
#include<string.h>

// Function to encrypt message using Caesar Cipher
char* encryptMessage(char* message, int key){
    int i;
    char ch;
    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];

        // Encrypt uppercase characters
        if(ch >= 'A' && ch <= 'Z'){
            ch = (ch + key - 'A') % 26 + 'A';
        }
        // Encrypt lowercase characters
        else if(ch >= 'a' && ch <= 'z'){
            ch = (ch + key - 'a') % 26 + 'a';
        }
        message[i] = ch;
    }
    return message;
}

int main(){
    char message[100];
    int key;

    printf("\nEnter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("\nEnter key: ");
    scanf("%d", &key);

    char* encryptedMessage = encryptMessage(message, key);

    printf("\nEncrypted message: %s", encryptedMessage);

    return 0;
}