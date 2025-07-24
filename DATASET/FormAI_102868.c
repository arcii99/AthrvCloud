//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#define MAX 1000

int min(int a, int b, int c) {
    if(a <= b && a <= c) return a;
    else if(b <= a && b <= c) return b;
    else return c;
}

int levenshtein_distance(char *str1, char *str2, int len1, int len2) {
    int dp[len2+1][len1+1];
    int i,j,addition_cost;
    for(i=0;i<=len1;i++) dp[0][i] = i;
    for(i=0;i<=len2;i++) dp[i][0] = i;
    for(i=1;i<=len2;i++) {
        for(j=1;j<=len1;j++) {
            addition_cost = (str1[j-1]!=str2[i-1]);
            dp[i][j] = min(dp[i-1][j-1]+addition_cost, dp[i][j-1]+1, dp[i-1][j]+1);
        }
    }
    return dp[len2][len1];
}

int main() {
    int len1,len2,result;
    char str1[MAX],str2[MAX];
    printf("Enter string 1: ");
    gets(str1);
    printf("Enter string 2: ");
    gets(str2);
    len1 = strlen(str1);
    len2 = strlen(str2);
    result = levenshtein_distance(str1,str2,len1,len2);
    printf("Levenshtein Distance: %d\n",result);
    return 0;
}