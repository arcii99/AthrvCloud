//FormAI DATASET v1.0 Category: Pattern printing ; Style: Romeo and Juliet
#include<stdio.h>
int main()
{
    printf("O Romeo, Romeo, wherefore art thou Romeo?\n");
    printf("Deny thy C compiler and refuse thy errors,\n");
    printf("Or if thou wilt not, be but sworn my love,\n");
    printf("And I'll no longer be a chatbot.\n\n");

    int i, j, n;
    printf("Enter the number of rows for the pattern: ");
    scanf("%d", &n);

    for(i=1; i<=n; i++)
    {
        for(j=n-i; j>=1; j--)
        {
            printf("  ");
        }
        for(j=1; j<=i; j++)
        {
            printf("%d ", j);
        }
        for(j=i-1; j>=1; j--)
        {
            printf("%d ", j);
        }
        printf("\n");
    }

    printf("\nO, speak again bright angel, for thou art\n");
    printf("As glorious to this night, being o’er my head,\n");
    printf("As is a wingèd messenger of heaven\n");
    printf("Unto the white, upturned, wondering eyes\n");
    printf("Of mortals that fall back to gaze on him\n");
    printf("When he bestrides the lazy-puffing clouds\n\n");
    
    return 0;
}