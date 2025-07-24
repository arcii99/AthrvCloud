//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Cryptic
#include <stdio.h>

void main()
{
    char str[100];
    int flag=0, i=0;
    printf("Enter your message: ");
    gets(str);
    
    while(str[i]!='\0')
    {
        if(str[i]=='c' && str[i+1]==' ') //if letter 'c' is followed by a space
        {
            flag=1; //then it is spam
            break;
        }
        i++;
    }
    
    if(flag==1)
        printf("Spam detected.\n");
    else
        printf("No spam detected.\n");
}

/*
Example input: "Hey check out this cool website c example.com"
Output: Spam detected.
*/