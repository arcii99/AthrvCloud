//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: statistical
#include<stdio.h>
#include<string.h>

int min(int a, int b, int c) 
{ 
    if(a<b && a<c) 
        return a; 
    else if(b<c) 
        return b; 
    else
        return c; 
} 

int lev_distance(char *str1, char *str2, int str1_len, int str2_len)
{
    int dp[str1_len+1][str2_len+1];
    
    for(int i=0;i<=str1_len;i++)
        dp[i][0] = i; //initialize the first column
    
    for(int i=0;i<=str2_len;i++)
        dp[0][i] = i; //initialize the first row
        
    for(int i=1;i<=str1_len;i++)
    {
        for(int j=1;j<=str2_len;j++)
        {
            if(str1[i-1] == str2[j-1]) //if the current characters match, copy value from diagonal
                dp[i][j] = dp[i-1][j-1];
            else //else, take the minimum value from adjacent cells and add 1
                dp[i][j] = min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]) + 1;
        }
    }
    
    return dp[str1_len][str2_len]; //return the minimum edit distance
}

int main()
{
    char str1[] = "levenstein";
    char str2[] = "levenshtein";
    int str1_len = strlen(str1);
    int str2_len = strlen(str2);

    printf("The Levenshtein distance between %s and %s is %d\n", str1, str2, lev_distance(str1, str2, str1_len, str2_len));
    
    return 0;
}