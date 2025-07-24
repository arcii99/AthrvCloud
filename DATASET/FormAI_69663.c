//FormAI DATASET v1.0 Category: Encryption ; Style: recursive
#include<stdio.h>
#include<string.h>

void encrypt(char* str, int len, int key)
{
    if (key == 0)
    {
        return;
    }
    int i;
    for (i=0; i<len; i++)
    {
        str[i] = (str[i] + key) % 128; //128 is the ASCII limit
    }
    encrypt(str, len, key-1);
}

void decrypt(char* str, int len, int key)
{
    if (key == 0)
    {
        return;
    }
    int i;
    for (i=0; i<len; i++)
    {
        str[i] = (str[i] - key) % 128; //128 is the ASCII limit
    }
    decrypt(str, len, key-1);
}

int main()
{
    char str[100];
    int key;
    printf("Enter a string: ");
    scanf("%[^\n]", str);
    getchar();
    printf("Enter the key: ");
    scanf("%d", &key);
    printf("Original string: %s\n", str);
    encrypt(str, strlen(str), key);
    printf("Encrypted string: %s\n", str);
    decrypt(str, strlen(str), key);
    printf("Decrypted string: %s\n", str);
    return 0;
}