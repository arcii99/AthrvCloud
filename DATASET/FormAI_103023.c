//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: irregular
#include<stdio.h>
#include<string.h>

int minimum(int a, int b, int c) {
  return (a<b)?((a<c)? a:c):((b<c)? b:c);
}

int levenshtein_distance(char * word1, char * word2) {
  int l1 = strlen(word1), l2 = strlen(word2);
  
  int dp[l1+1][l2+1];
  
  for(int i=0;i<=l1;i++) {
    for(int j=0;j<=l2;j++) {
      if(i==0)
        dp[i][j] = j;
      else if(j==0)
        dp[i][j] = i;
      else if(word1[i-1] == word2[j-1])
        dp[i][j] = dp[i-1][j-1];
      else {
        dp[i][j] = 1 + minimum(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);
      }
    }
  }
  
  return dp[l1][l2];
}

int main() {
  char word1[20], word2[20];
  
  printf("Enter the first word: ");
  scanf("%s", word1);
  
  printf("Enter the second word: ");
  scanf("%s", word2);
  
  printf("The Levenshtein distance between %s and %s is %d", word1, word2, levenshtein_distance(word1, word2));
  
  return 0;
}