//FormAI DATASET v1.0 Category: modern Encryption ; Style: bold
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

// function to encrypt the given string
char* encrypt(char* str, int key)
{
    int len = strlen(str);
    char* encstr = (char*)malloc(len*sizeof(char));

    for(int i=0;i<len;i++)
    {
        // perform XOR operation on each character
        encstr[i] = str[i] ^ key;
    }

    return encstr;
}

int main()
{
    printf("Enter the string to be encrypted: ");
    char str[50];
    scanf("%s", str);

    // generate a random key between 0 and 255
    srand(time(NULL));
    int key = rand() % 256;

    char* encstr = encrypt(str, key);

    printf("\nOriginal string: %s", str);
    printf("\nEncrypted string: %s", encstr);
    printf("\nKey used for encryption: %d", key);

    free(encstr);
    return 0;
}