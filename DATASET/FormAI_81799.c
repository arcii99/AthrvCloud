//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: cheerful
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
  if(a < b && a < c) return a;
  if(b < a && b < c) return b;
  return c;
}

int levenshteinDistance(char *s1, char *s2) {
  int rows = strlen(s1) + 1;
  int cols = strlen(s2) + 1;
  int distance[rows][cols];

  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
      if(i == 0) distance[i][j] = j;
      else if(j == 0) distance[i][j] = i;
      else distance[i][j] = 0;
    }
  }

  for(int i = 1; i < rows; i++) {
    for(int j = 1; j < cols; j++) {
      if(s1[i - 1] == s2[j - 1])
        distance[i][j] = distance[i-1][j-1];
      else
        distance[i][j] = min(distance[i-1][j-1] + 1, distance[i][j-1] + 1, distance[i-1][j] + 1);
    }
  }

  return distance[rows-1][cols-1];
}

int main() {
  char s1[100], s2[100];

  printf("Hello! I am a cheerful Levenshtein Distance Calculator. Please enter the first string: ");
  scanf("%s", s1);

  printf("Great! Now enter the second string: ");
  scanf("%s", s2);

  printf("The Levenshtein Distance between '%s' and '%s' is: %d\n", s1, s2, levenshteinDistance(s1, s2));

  printf("Thanks for using me. Have a cheerful day!\n");

  return 0;
}