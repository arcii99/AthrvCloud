//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: excited
#include <stdio.h>
#include <string.h>

int levenshteinDistance(char word1[], char word2[]) {
    int m = strlen(word1);
    int n = strlen(word2);
    int dp[m+1][n+1];
    
    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            if(i == 0) {
                dp[i][j] = j;
            } else if(j == 0) {
                dp[i][j] = i;
            } else {
                dp[i][j] = dp[i-1][j-1];
                if(word1[i-1] != word2[j-1]) {
                    dp[i][j]++;
                }
                if(dp[i][j] > dp[i-1][j] + 1) {
                    dp[i][j] = dp[i-1][j] + 1;
                }
                if(dp[i][j] > dp[i][j-1] + 1) {
                    dp[i][j] = dp[i][j-1] + 1;
                }
            }
        }
    }
    
    return dp[m][n];
}

int main() {
    char word1[] = "Hello";
    char word2[] = "Holla";
    int distance = levenshteinDistance(word1, word2);

    printf("The Levenshtein Distance between %s and %s is %d!\n", word1, word2, distance);
    printf("Isn't that just amazing? This program can calculate the Levenshtein distance between any two words you want. \n");
    printf("This comes in handy when you want to know how many operations it would take to turn one word into another.\n");
    printf("And the best part is that this program is super efficient as it has a time complexity of O(m*n)!\n");
    printf("You can even use this program to find the difference between two DNA sequences or to check the similarity between two programming codes!\n");
    printf("I hope you enjoyed this program. Happy coding!\n");

    return 0;
}