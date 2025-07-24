//FormAI DATASET v1.0 Category: Encryption ; Style: brave
#include<stdio.h>
#include<string.h>

int main()
{
    char string[100];
    int i,key;

    printf("Enter the string to be encrypted:");
    fgets(string, sizeof(string), stdin);

    printf("Enter the key (1-25):");
    scanf("%d",&key);

    for(i = 0; i < strlen(string); i++)
    {
        if(string[i] >= 'a' && string[i] <= 'z')
        {
            string[i] = (string[i] + key - 'a') % 26 + 'a';
        }
        else if(string[i] >= 'A' && string[i] <= 'Z')
        {
            string[i] = (string[i] + key - 'A') % 26 + 'A';
        }
    }

    printf("The encrypted string is: %s",string);

    return 0;
}