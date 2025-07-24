//FormAI DATASET v1.0 Category: Compression algorithms ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char input[100], compressed[100];
  int count[100], i, j, k, n;

  printf("Enter a string to compress: ");
  scanf("%[^\n]", input);

  n = strlen(input);

  for (i = 0; i < n; i++)
  {
    count[i] = 1;
    for (j = i + 1; j < n; j++)
    {
      if (input[i] != input[j])
        break;
      count[i]++;
    }
    i = j - 1;
  }

  k = 0;
  for (i = 0; i < n; i++)
  {
    compressed[k++] = input[i];
    char str[10];
    sprintf(str, "%d", count[i]);
    if (count[i] > 1)
    {
      for (j = 0; str[j] != '\0'; j++)
      {
        compressed[k++] = str[j];
      }
    }
  }
  compressed[k] = '\0';

  printf("The compressed string is: %s\n", compressed);

  return 0;
}