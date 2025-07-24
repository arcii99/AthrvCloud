//FormAI DATASET v1.0 Category: Modern Encryption ; Style: medieval
#include<stdio.h>
#include<string.h>

int main()
{
    char str[100];
    int key;
    printf("Enter a string to encrypt: ");
    scanf("%[^\n]", str);
    printf("Enter a key: ");
    scanf("%d", &key);

    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]>='A' && str[i]<='Z')
        {
            str[i] = (((str[i]-'A')+key)%26)+'A';
        }
        else if(str[i]>='a' && str[i]<='z')
        {
            str[i] = (((str[i]-'a')+key)%26)+'a';
        }
    }

    printf("Encrypted string: %s", str);
    return 0;
}