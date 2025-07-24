//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: random
#include <stdio.h>
#include <string.h>
#define MAX_LEN 100

int min(int a, int b, int c){
    int min = a;
    if(b < min) min = b;
    if(c < min) min = c;
    return min;
}

int LevenshteinDistance(char* s1, char* s2, int len1, int len2){
    int dp[MAX_LEN][MAX_LEN];
    for(int i = 0; i <= len1; i++){
        for(int j = 0; j <= len2; j++){
            if(i == 0) dp[i][j] = j;
            else if(j == 0) dp[i][j] = i;
            else if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
        }
    }
    return dp[len1][len2];
}

void randomFunc(){
    printf("Hello, let's play a game! I will give you two words and you need to guess the Levenshtein Distance between them.\n");
    printf("Type 'exit' to stop playing.\n");
    char s1[MAX_LEN], s2[MAX_LEN];
    while(1){   // infinite loop
        printf("\nEnter the first word: ");
        scanf("%s", s1);
        if(strcmp("exit", s1) == 0) break;
        printf("Great! Now enter the second word: ");
        scanf("%s", s2);
        if(strcmp("exit", s2) == 0) break;
        int len1 = strlen(s1), len2 = strlen(s2);
        int distance = LevenshteinDistance(s1, s2, len1, len2);
        printf("The Levenshtein Distance between %s and %s is %d.\n\n", s1, s2, distance);
    }
    printf("Thank you for playing!");
}

int main(){
    randomFunc();
    return 0;
}