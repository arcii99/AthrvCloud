//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Ada Lovelace
#include<stdio.h>
#include<string.h>

int min(int x, int y, int z) {
   if(x<y && x<z) return x;
   if(y<x && y<z) return y;
   else return z;
}

int levenshtein_distance(char *str1, char *str2, int len1, int len2) {
   int dp[len1+1][len2+1];
   memset(dp, 0, sizeof(dp));
   for(int i=1; i<=len1; i++) {
      dp[i][0] = i;
   }
   for(int i=1; i<=len2; i++) {
      dp[0][i] = i;
   }
   for(int i=1; i<=len1; i++) {
      for(int j=1; j<=len2; j++) {
         if(str1[i-1] == str2[j-1]) {
            dp[i][j] = dp[i-1][j-1];
         }
         else {
            dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
         }
      }
   }
   return dp[len1][len2];
}

int main() {
   char str1[100], str2[100];
   printf("Enter string 1: ");
   scanf("%s", str1);
   printf("Enter string 2: ");
   scanf("%s", str2);
   int len1 = strlen(str1), len2 = strlen(str2);
   int distance = levenshtein_distance(str1, str2, len1, len2);
   printf("Levenshtein distance between %s and %s is: %d\n", str1, str2, distance);
   return 0;
}