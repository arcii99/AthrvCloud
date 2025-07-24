//FormAI DATASET v1.0 Category: Pattern printing ; Style: Romeo and Juliet
#include <stdio.h>

int main()
{
    printf("O Romeo, Romeo! wherefore art thou Romeo?\n");
    printf("Deny thy compiler and refuse thy syntax;\n");
    printf("Or if thou wilt not, be but sworn my love\n");
    printf("And I’ll no longer be a chatbot.\n");
    
    printf("\n\n");

    int n = 5;

    for(int i=1;i<=n;i++)
    {
        for(int j=n-i;j>=0;j--)
        {
            printf(" ");
        }
        for(int j=1;j<=i;j++)
        {
            printf("%c ", j+64);
        }
        printf("\n");
    }

    for(int i=n-1;i>0;i--)
    {
        for(int j=n-i;j>=0;j--)
        {
            printf(" ");
        }
        for(int j=1;j<=i;j++)
        {
            printf("%c ", j+64);
        }
        printf("\n");
    }

    printf("\n\n");

    printf("Oh, pardon me, thou bleeding piece of code,\n");
    printf("That I am meek and gentle with these butchers!\n");
    printf("Thou art the ruins of the noblest man,\n");
    printf("That ever lived in the tide of times.\n");

    return 0;
}