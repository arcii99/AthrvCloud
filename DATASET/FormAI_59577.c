//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: sophisticated
#include<stdio.h>
#include<string.h>
 
int min(int a,int b,int c)
{
    if(a<b && a<c)
        return a;
    else if(b<a && b<c)
        return b;
    else
        return c;
}
 
int levenshtein_distance(char *str1,char *str2)
{
    int len1=strlen(str1);
    int len2=strlen(str2);
    int i,j;
    int dp[len1+1][len2+1];
    for(i=0;i<=len1;i++)
        dp[i][0]=i;
    for(j=0;j<=len2;j++)
        dp[0][j]=j;
    for(i=1;i<=len1;i++)
    {
        for(j=1;j<=len2;j++)
        {
            if(str1[i-1]==str2[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1;
        }
    }
    return dp[len1][len2];
}
 
int main()
{
    char str1[100],str2[100];
    printf("Enter String 1: ");
    scanf("%s",str1);
    printf("Enter String 2: ");
    scanf("%s",str2);
    printf("Levenshtein Distance between %s and %s is %d\n", str1, str2, levenshtein_distance(str1,str2));
    return 0;
}