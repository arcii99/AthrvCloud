//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: expert-level
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
  if(a < b && a < c)
    return a;
  else if(b < a && b < c)
    return b;
  else
    return c;
}

int levenshteinDistance(char* s1, char* s2) {
  int len1 = strlen(s1);
  int len2 = strlen(s2);
  int distanceMatrix[len1+1][len2+1];

  for(int i = 0; i <= len1; i++) {
    for(int j = 0; j <= len2; j++) {
      if(i == 0)
        distanceMatrix[i][j] = j;
      else if(j == 0)
        distanceMatrix[i][j] = i;
      else if(s1[i-1] == s2[j-1])
        distanceMatrix[i][j] = distanceMatrix[i-1][j-1];
      else
        distanceMatrix[i][j] = 1 + min(distanceMatrix[i-1][j], distanceMatrix[i-1][j-1], distanceMatrix[i][j-1]);
    }
  }

  return distanceMatrix[len1][len2];
}

int main() {
  char s1[100], s2[100];
  printf("Enter string 1: ");
  scanf("%s", s1);
  printf("Enter string 2: ");
  scanf("%s", s2);
  printf("Levenshtein Distance between \n%s \nand \n%s \nis: %d", s1, s2, levenshteinDistance(s1, s2));
  return 0;
}