//FormAI DATASET v1.0 Category: String manipulation ; Style: optimized
#include <stdio.h>
#include <string.h>

int main() {
  char str1[100];
  char str2[100];

  // read input strings from user
  printf("Enter the first string: ");
  fgets(str1, 100, stdin);
  printf("Enter the second string: ");
  fgets(str2, 100, stdin);

  // check that both strings have at least two characters
  if (strlen(str1) < 2 || strlen(str2) < 2) {
    printf("Error: both strings must be at least two characters long\n");
    return 1;
  }

  // swap first two characters using pointer arithmetic
  char temp = *str1;
  *str1 = *str2;
  *str2 = temp;
  temp = *(str1 + 1);
  *(str1 + 1) = *(str2 + 1);
  *(str2 + 1) = temp;

  // print swapped strings
  printf("Swapped strings:\n%s%s", str1, str2);

  return 0;
}