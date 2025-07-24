//FormAI DATASET v1.0 Category: Encryption ; Style: recursive
#include<stdio.h>
#include<string.h>

void encrypt(char str[], int key)
{
    int i;
    if(str[i] == '\0')
    {
        return; // base case - if end of string is detected, return
    }
    else
    {
        printf("%c", str[i] + key); // encrypting the character by adding the key
        encrypt(str + 1, key); // recursive call to next character in string
    }
}

int main()
{
    char message[100];
    int key;
    printf("Enter the message you want to encrypt: ");
    fgets(message, 100, stdin); // getting input from user
    printf("Enter the encryption key: ");
    scanf("%d", &key);
    printf("Encrypted message: ");
    encrypt(message, key);
    return 0;
}