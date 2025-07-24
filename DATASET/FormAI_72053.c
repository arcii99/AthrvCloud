//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: energetic
#include<stdio.h>
#include<string.h>

int min(int x,int y,int z)
{
    if(x <= y && x <= z)
        return x;
    else if(y <= x && y <= z)
        return y;
    else
        return z;
}

int LevenshteinDistance(char *string1,char *string2,int m,int n)
{
    int i,j,ld[m+1][n+1];
    for(i=0;i<=m;i++)
        ld[i][0] = i;
    for(j=0;j<=n;j++)
        ld[0][j] = j;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(string1[i-1] == string2[j-1])
                ld[i][j] = ld[i-1][j-1];
            else
                ld[i][j] = min(ld[i-1][j],ld[i][j-1],ld[i-1][j-1]) + 1;
        }
    }
    return ld[m][n];
}

int main()
{
    char string1[100],string2[100];
    printf("Please enter the first string: ");
    scanf("%s",string1);
    printf("Please enter the second string: ");
    scanf("%s",string2);
    int distance = LevenshteinDistance(string1,string2,strlen(string1),strlen(string2));
    printf("The Levenshtein distance between %s and %s is %d",string1,string2,distance);
    return 0;
}