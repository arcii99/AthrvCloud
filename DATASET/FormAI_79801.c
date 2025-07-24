//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: active
#include <stdio.h>
#include <string.h>

int main()
{
  char input[100], checksum[20], temp[20];
  int i, len, j = 0, sum = 0;

  printf("Enter the input string: ");
  scanf("%s", input);

  len = strlen(input);

  for (i = 0; i < len; i++)
  {
    sum += input[i];
  }

  sprintf(temp, "%d", sum);
  len = strlen(temp);

  for (i = 0; i < len; i++)
  {
    checksum[j++] = temp[i];
  }

  printf("The checksum is: %s", checksum);

  return 0;
}