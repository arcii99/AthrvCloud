//FormAI DATASET v1.0 Category: Compression algorithms ; Style: shocked
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int i,j,k, length, flag, count=1;
    char str[100];

    printf("Enter a string to compress: ");
    scanf("%s",&str);

    length = strlen(str);

    for(i=0; i<length; i++)
    {
        if(str[i]==str[i+1])
        {
            count++;
        }
        else
        {
            if(count>1)
            {
                printf("%c%d", str[i], count);
                count=1;
            }
            else
            {
                printf("%c",str[i]);
            }
        }
    }
    return 0;
}