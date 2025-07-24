//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: creative
#include<stdio.h>
#include<string.h>

int minimum(int a, int b, int c) {
   if(a<b && a<c)
      return a;
   if(b<a && b<c)
      return b;

   return c;
}

int levenshtein_distance(char *string1, char *string2) {
   int len1 = strlen(string1);
   int len2 = strlen(string2);
   int i, j, cost;
   int matrix[len1+1][len2+1];

   for(i=0; i<=len1; i++)
      matrix[i][0] = i;

   for(j=0; j<=len2; j++)
      matrix[0][j] = j;

   for(i=1; i<=len1; i++) {
      for(j=1; j<=len2; j++) {
         cost = (string1[i-1] == string2[j-1]) ? 0 : 1;

         matrix[i][j] = minimum(matrix[i-1][j]+1, matrix[i][j-1]+1, matrix[i-1][j-1]+cost);
      }
   }

   return matrix[len1][len2];
}

int main() {
   char *string1 = "kitten";
   char *string2 = "sitting";
   int distance;

   distance = levenshtein_distance(string1, string2);

   printf("The Levenshtein Distance between %s and %s is : %d\n", string1, string2, distance);

   return 0;
}