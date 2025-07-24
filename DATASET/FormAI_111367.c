//FormAI DATASET v1.0 Category: Modern Encryption ; Style: imaginative
#include <stdio.h>
#include <string.h>

// Encryption function using modern encryption algorithm
void encrypt(char *input, int key) {
    int i;
    int len = strlen(input);
    for(i=0; i<len; i++) {
        if(input[i]>='a' && input[i]<='z') {
            input[i] = ((input[i]+key-'a')%26)+'a';
        } else if(input[i]>='A' && input[i]<='Z') {
            input[i] = ((input[i]+key-'A')%26)+'A';
        }
    }
}

// Decryption function using modern encryption algorithm
void decrypt(char *input, int key) {
    int i;
    int len = strlen(input);
    for(i=0; i<len; i++) {
        if(input[i]>='a' && input[i]<='z') {
            input[i] = ((input[i]-key-'a'+26)%26)+'a';
        } else if(input[i]>='A' && input[i]<='Z') {
            input[i] = ((input[i]-key-'A'+26)%26)+'A';
        }
    }
}

int main() {
    char input[100];
    int key;

    // Get input string and key from the user
    printf("Enter a string to encrypt: ");
    fgets(input, 100, stdin);
    printf("Enter a key: ");
    scanf("%d", &key);

    // Encrypt the string and print it
    encrypt(input, key);
    printf("Encrypted string: %s", input);

    // Decrypt the string and print it
    decrypt(input, key);
    printf("Decrypted string: %s", input);

    return 0;
}