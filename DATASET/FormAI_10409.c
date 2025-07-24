//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int minimum(int a, int b, int c) {
   int min = a;
   if(min > b)
      min = b;
   if(min > c)
      min = c;
   return min;
}

int lev(char *s, char *t, int len1, int len2) {
   int d[len1+1][len2+1];
   for(int i=0; i<=len1; i++)
      d[i][0] = i;
   for(int j=0; j<=len2; j++)
      d[0][j] = j;

   for(int i=1; i<=len1; i++) {
      for(int j=1; j<=len2; j++) {
         int cost = (s[i-1] == t[j-1]) ? 0 : 1;
         d[i][j] = minimum(d[i-1][j]+1, d[i][j-1]+1, d[i-1][j-1]+cost);
      }
   }
   return d[len1][len2];
}

int main() {
   char *s = "BENDER";
   char *t = "RODRIGUEZ";
   int len1 = strlen(s);
   int len2 = strlen(t);
   int res = lev(s, t, len1, len2);
   printf("The Levenshtein distance between BENDER and RODRIGUEZ is %d\n", res);
   return 0;
}