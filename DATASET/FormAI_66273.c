//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: realistic
#include <stdio.h>
#include <string.h>

int main()
{
    char string[100];
    int i,j,c=0;

    printf("Enter a string: ");
    fgets(string,100,stdin);
    
    // Removing the newline character
    string[strcspn(string, "\n")] = 0;

    j=strlen(string) - 1;

    for(i=0;i<j;i++,j--)
    {
        if(string[i]!=string[j])
        {
            c=1;
            break;
        }
    }

    if(c==0)
        printf("%s is a palindrome.\n",string);
    else
        printf("%s is not a palindrome.\n",string);

    return 0;
}