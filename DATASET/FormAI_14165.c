//FormAI DATASET v1.0 Category: Modern Encryption ; Style: light-weight
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

void encrypt(char *text, int key) {
    int len = strlen(text);
    for(int i=0; i<len; i++) {
        if(text[i]>='a' && text[i]<='z') {
            text[i] = 'a' + (text[i]-'a'+key)%26;
        }
        else if(text[i]>='A' && text[i]<='Z') {
            text[i] = 'A' + (text[i]-'A'+key)%26;
        }
    }
}

void decrypt(char *text, int key) {
    int len = strlen(text);
    for(int i=0; i<len; i++) {
        if(text[i]>='a' && text[i]<='z') {
            text[i] = 'a' + (text[i]-'a'-key+26)%26;
        }
        else if(text[i]>='A' && text[i]<='Z') {
            text[i] = 'A' + (text[i]-'A'-key+26)%26;
        }
    }
}

int main() {
    char text[MAX_LENGTH];
    int key;

    printf("Enter the text to encrypt: ");
    fgets(text, MAX_LENGTH, stdin);
    printf("Enter the encryption key: ");
    scanf("%d", &key);

    encrypt(text, key);
    printf("Encrypted text: %s\n", text);

    decrypt(text, key);
    printf("Decrypted text: %s\n", text);

    return 0;
}