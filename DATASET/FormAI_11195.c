//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Cryptic
// Decrypting the Syntax
#include <stdio.h>

void main()
{
    int i=0,j=0,k=0;
    char input[50]="my secret code";
    char output[50]={'\0'};
    
    for(i=0;input[i]!=0;i++)
    {
        if((int)input[i]%3==0)
            output[j++]=(char)((int)input[i]/3);
        else
            output[j++]=(char)((int)input[i]+15);

        if(j%2==0)
        {
            output[j++]='*';
            output[j-2]='.';
        }

        if(j%5==0)
        {
            for(k=j-5;k<j;k++)
            {
                printf("%c",output[k]);
            }
            printf("\n");
        }
    }

    if(j%5!=0)
    {
        for(k=j-(j%5);k<j;k++)
        {
            printf("%c",output[k]);
        }
    }
}