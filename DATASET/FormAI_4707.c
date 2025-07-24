//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: satisfied
#include<stdio.h>
#include<string.h>

int min(int a, int b, int c)
{
    if(a<b && a<c)
       return a;
    else if(b<a && b<c)
       return b;
    else
       return c;
}

int levenshtein_distance(char *str1, char *str2, int m, int n)
{
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++)
      dp[i][0]=i;
    for(int i=0;i<=n;i++)
      dp[0][i]=i;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(str1[i-1]==str2[j-1])
              dp[i][j]=dp[i-1][j-1];
            else
            {
                dp[i][j]=1+min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]);
            }
        }
    }
    
    return dp[m][n];
}

int main()
{
    char str1[100],str2[100];
    printf("Enter the first string: ");
    scanf("%s",str1);
    printf("\nEnter the second string: ");
    scanf("%s",str2);
    int m=strlen(str1);
    int n=strlen(str2);
    int ld=levenshtein_distance(str1,str2,m,n);
    printf("\nThe Levenshtein distance between the two given strings is: %d",ld);
    return 0;
}