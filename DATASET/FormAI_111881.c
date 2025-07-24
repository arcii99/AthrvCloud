//FormAI DATASET v1.0 Category: String manipulation ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

int main() {
  char str1[50] = "Hello,";
  char str2[50] = " World!";

  printf("String 1: %s\n", str1);
  printf("String 2: %s\n", str2);

  printf("\n----- String Concatenation -----\n");
  strcat(str1, str2);
  printf("Concatenated String: %s\n", str1);

  printf("\n----- String Comparison -----\n");
  if(strcmp(str1, str2) == 0) {
    printf("Strings are the same.\n");
  } else {
    printf("Strings are NOT the same.\n");
  }

  printf("\n----- String Copying -----\n");
  strcpy(str1, "Goodbye!");
  printf("New String 1: %s\n", str1);

  printf("\n----- String Length -----\n");
  printf("Length of String 1: %lu\n", strlen(str1));

  printf("\n----- Substring -----\n");
  char sub[10];
  strncpy(sub, str1+3, 5);
  sub[5] = '\0';
  printf("Substring: %s\n", sub);

  return 0;
}