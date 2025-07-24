//FormAI DATASET v1.0 Category: Encryption ; Style: shocked
#include<stdio.h>
#include<string.h>

int main(){

    char str[100], key[50];
    int keyLen, strLen, i, j;

    printf("Enter a message to encrypt: ");
    scanf("%[^\n]s", str);

    printf("\nEnter encryption key: ");
    scanf("%s", key);

    strLen = strlen(str);
    keyLen = strlen(key);

    for(i = 0; i < strLen; i++){
        str[i] = str[i] ^ key[i % keyLen]; //XOR the ith character with the ith character of key
    }

    printf("\nEncrypted message: %s\n", str);

    return 0;
}