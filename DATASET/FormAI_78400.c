//FormAI DATASET v1.0 Category: Encryption ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    //declaring variables
    char str[100];
    int key = 3;
    int len, i;
    
    printf("Enter a message to encrypt: ");
    scanf("%s", str);
    
    len = strlen(str);
    
    //encrypting each character of the message
    for(i = 0; i < len; i++)
    {
        str[i] = str[i] + key;
    }
    
    //printing the encrypted message
    printf("Encrypted message: %s", str);
    
    return 0;
}