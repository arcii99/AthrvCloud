//FormAI DATASET v1.0 Category: String manipulation ; Style: mathematical
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
  char str[100];
  int i, len, count = 0, sum = 0;

  printf("Enter a string: ");
  fgets(str, 100, stdin);

  len = strlen(str);

  for (i = 0; i < len; i++) {
    if (isdigit(str[i])) {
      count++;
      sum += str[i] - '0';
    }
  }

  printf("The number of digits in the string is: %d\n", count);
  printf("The sum of the digits in the string is: %d\n", sum);

  return 0;
}