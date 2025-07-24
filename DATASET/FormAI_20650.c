//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 1024

int cost(char a, char b){
    if(a==b) return 0;
    return 1;
}

int levenshtein_distance(char *s1, char *s2){
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    int **dp = (int**) calloc(n1+1, sizeof(int*));
    for(int i=0; i<=n1; i++) dp[i] = (int*) calloc(n2+1, sizeof(int));
    for(int i=0; i<=n1; i++) dp[i][0] = i;
    for(int j=0; j<=n2; j++) dp[0][j] = j;
    for(int i=1; i<=n1; i++){
        for(int j=1; j<=n2; j++){
            dp[i][j] = dp[i-1][j]+1;
            if(dp[i][j-1]+1<dp[i][j]) dp[i][j] = dp[i][j-1]+1;
            if(dp[i-1][j-1]+cost(s1[i-1], s2[j-1])<dp[i][j]) dp[i][j] = dp[i-1][j-1]+cost(s1[i-1], s2[j-1]);
        }
    }
    int res = dp[n1][n2];
    for(int i=0; i<=n1; i++) free(dp[i]);
    free(dp);
    return res;
}

int main(){
    char s1[MAXLEN], s2[MAXLEN];
    printf("Enter the first string: ");
    fgets(s1, MAXLEN, stdin);
    s1[strcspn(s1, "\r\n")] = '\0';
    printf("Enter the second string: ");
    fgets(s2, MAXLEN, stdin);
    s2[strcspn(s2, "\r\n")] = '\0';
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", s1, s2, levenshtein_distance(s1, s2));
    return 0;
}