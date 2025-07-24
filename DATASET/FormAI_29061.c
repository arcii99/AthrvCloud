//FormAI DATASET v1.0 Category: String manipulation ; Style: peaceful
#include <stdio.h>
#include <string.h>

int main()
{
  char str1[100], str2[100], str3[100];
  int len;

  printf("Enter a sentence: ");
  fgets(str1, 100, stdin); // Read input from user

  // Remove newline character from input
  len = strlen(str1);
  if (str1[len-1] == '\n')
    str1[len-1] = '\0';

  // Capitalize every other character
  for (int i = 0; i < strlen(str1); i += 2) {
    str2[i] = str1[i] - 32;
    str2[i+1] = str1[i+1];
  }
  str2[strlen(str1)] = '\0';

  // Reverse the string
  int j = 0;
  for (int i = strlen(str2) - 1; i >= 0; i--) {
    str3[j] = str2[i];
    j++;
  }
  str3[strlen(str2)] = '\0';

  // Print the result
  printf("The manipulated string is: %s\n", str3);

  return 0;
}