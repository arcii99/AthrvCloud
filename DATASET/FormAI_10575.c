//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Cryptic
#include <stdio.h>
#include <string.h>

int min(int x, int y, int z) {
   if (x <= y && x <= z) return x;
   if (y <= x && y <= z) return y;
   return z;
}

int lev_dist(char *a, char *b) {
   int n = strlen(a);
   int m = strlen(b);
   int i, j, d[n + 1][m + 1];

   for (i = 0; i <= n; i++) d[i][0] = i;
   for (j = 0; j <= m; j++) d[0][j] = j;

   for (i = 1; i <= n; i++) {
      for (j = 1; j <= m; j++) {
         int cost = a[i - 1] == b[j - 1] ? 0 : 1;

         d[i][j] = min(d[i - 1][j] + 1,
                       d[i][j - 1] + 1,
                       d[i - 1][j - 1] + cost);
      }
   }

   return d[n][m];
}

int main() {
   char a[] = "cryptic";
   char b[] = "coding";

   printf("The Levenshtein distance between %s and %s is %d\n", a, b, lev_dist(a, b));

   return 0;
}