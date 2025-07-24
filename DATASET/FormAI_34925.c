//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: surprised
#include<stdio.h>
#include<string.h>
#define max 100000
int d[1010][1010]; // declare the array dimensions
 
int min(int a,int b,int c)
{
    if(a<b&&a<c)
        return a;
    else if(b<a&&b<c)
        return b;
    else
        return c;
}
int main()
{
    char s1[1010],s2[1010];
    printf("Surprise! Let's calculate the Levenshtein Distance between two Strings!\n\nEnter First String : ");
    scanf("%s",s1);
    printf("Enter Second String : ");
    scanf("%s",s2); // Taking input from the user
 
    int l1=strlen(s1);
    int l2=strlen(s2);
 
    int i,j;
    for(i=0;i<=l2;i++)
        d[0][i]=i;
    for(i=0;i<=l1;i++)
        d[i][0]=i; // Initialization
 
    for(i=1;i<=l1;i++)
    {
        for(j=1;j<=l2;j++)
        {
            if(s1[i-1]==s2[j-1])
                d[i][j]=d[i-1][j-1];
            else
                d[i][j]=min(d[i-1][j]+1,d[i][j-1]+1,d[i-1][j-1]+1);
        }
    } //Computing the Levenshtein Distance
 
    printf("\nSURPRISE! The Levenshtein Distance of the two strings is : %d\n\n",d[l1][l2]); // Printing the result
    return 0; 
}