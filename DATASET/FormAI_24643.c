//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

int minimum(int a, int b, int c)
{
  if (a < b && a < c)
    return a;
  else if (b < a && b < c)
    return b;
  else
    return c;
}

int levenshtein_distance(char *str1, char *str2)
{
  int str1_len = strlen(str1);
  int str2_len = strlen(str2);

  int dist[str1_len + 1][str2_len + 1];

  for (int i = 0; i <= str1_len; i++)
    {
      for (int j = 0; j <= str2_len; j++)
    {
      if (i == 0)
        {
          dist[i][j] = j;
        }
      else if (j == 0)
        {
          dist[i][j] = i;
        }
      else if (str1[i - 1] == str2[j - 1])
        {
          dist[i][j] = dist[i - 1][j - 1];
        }
      else
        {
          dist[i][j] = 1 + minimum(dist[i][j - 1], dist[i - 1][j], dist[i - 1][j - 1]);
        }
    }
    }

  return dist[str1_len][str2_len];
}

int main()
{
  char str1[MAX_LEN], str2[MAX_LEN];

  printf("Enter first string: ");
  fgets(str1, MAX_LEN, stdin);
  str1[strcspn(str1, "\n")] = 0; // remove newline character

  printf("Enter second string: ");
  fgets(str2, MAX_LEN, stdin);
  str2[strcspn(str2, "\n")] = 0; // remove newline character

  int distance = levenshtein_distance(str1, str2);

  printf("The Levenshtein distance between \"%s\" and \"%s\" is %d\n", str1, str2, distance);

  return 0;
}