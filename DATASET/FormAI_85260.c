//FormAI DATASET v1.0 Category: Text processing ; Style: protected
#include<stdio.h>
#include<string.h>

void protect(char *str)
{
    int len = strlen(str);
    for(int i=0; i<len; i++)
    {
        if(str[i] == 'a')
        {
            str[i] = '@';
        }
        else if(str[i] == 'e')
        {
            str[i] = '3';
        }
        else if(str[i] == 'i')
        {
            str[i] = '1';
        }
        else if(str[i] == 'o')
        {
            str[i] = '0';
        }
        else if(str[i] == 's')
        {
            str[i] = '$';
        }
    }
}

int main()
{
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    printf("Original String: %s", str);
    protect(str);
    printf("Protected String: %s", str);
    return 0;
}