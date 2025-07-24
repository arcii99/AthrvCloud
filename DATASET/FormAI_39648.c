//FormAI DATASET v1.0 Category: Encryption ; Style: recursive
#include<stdio.h>
#include<string.h>

void encrypt(char [], int);

int main()
{
    char text[100];

    printf("\nEnter a message to encrypt: ");
    fgets(text, 100, stdin);

    printf("\nEncrypted message: ");
    encrypt(text, 0);

    return 0;
}

void encrypt(char arr[], int index)
{
    if(index == strlen(arr))
        return;
    
    char ch = arr[index];

    if(ch >= 'a' && ch <= 'z')
        ch = 'a' + ('z' - ch);

    else if(ch >= 'A' && ch <= 'Z')
        ch = 'A' + ('Z' - ch);

    printf("%c", ch);
    encrypt(arr, index+1);
}