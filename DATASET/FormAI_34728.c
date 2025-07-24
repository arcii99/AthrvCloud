//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Encrypt function*/
void encrypt(char* str, char* key) {
    int lenKey = strlen(key);
    int lenStr = strlen(str);
    int repetition = lenStr / lenKey + (lenStr % lenKey == 0 ? 0 : 1);
    char* newKey = (char*)malloc(sizeof(char) * repetition * lenKey + 1);
    for(int i = 0; i < repetition; i++)
        strcat(newKey, key);
    newKey[lenStr] = '\0';
    for(int i = 0; i < lenStr; i++)
        str[i] ^= newKey[i];
}

/*Decrypt function*/
void decrypt(char* str, char* key) {
    encrypt(str, key); //Decryption is just the same as encryption
}

int main() {
    char originalText[] = "Hello, World!";
    char key[] = "SuperSecretKey";
    encrypt(originalText, key);
    printf("%s\n", originalText);
    decrypt(originalText, key);
    printf("%s\n", originalText);
    return 0;
}