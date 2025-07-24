//FormAI DATASET v1.0 Category: Pattern printing ; Style: Romeo and Juliet
#include<stdio.h>
void main()
{
    int i,j,k;
    char l = 65; //ASCII value of A
    for(i=1;i<=5;i++)
    {
        for(j=5;j>=i;j--)
        {
            printf(" ");
        }
        for(k=1;k<=i;k++)
        {
            printf("%c",l);
            l++;
        }
        l -= 2;
        for(k=1;k<i;k++)
        {
            printf("%c",l);
            l--;
        }
        printf("\n");
    }
    l -= 12;
    for(i=4;i>=1;i--)
    {
        for(j=5;j>=i;j--)
        {
            printf(" ");
        }
        for(k=1;k<=i;k++)
        {
            printf("%c",l);
            l++;
        }
        l -= 2;
        for(k=1;k<i;k++)
        {
            printf("%c",l);
            l--;
        }
        printf("\n");
    }
    printf("O Romeo, Romeo, wherefore art thou Romeo?\n");
    printf("Deny thy father and refuse thy name;\n");
    printf("Or if thou wilt not, be but sworn my love\n");
    printf("And I'll no longer be a Capulet.\n");
    printf("                                   - Juliet");
}