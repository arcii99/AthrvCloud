//FormAI DATASET v1.0 Category: String manipulation ; Style: peaceful
#include <stdio.h>
#include <string.h>

int main() {
  char str1[50], str2[50], temp[50];
  printf("Enter a string: ");
  scanf("%s", str1);
  printf("Enter another string: ");
  scanf("%s", str2);

  // concatenate the two strings
  strcat(str1, str2);
  printf("Concatenated string: %s\n", str1);

  // find the length of the string
  int length = strlen(str1);
  printf("Length of string: %d\n", length);

  // reverse the string
  int i, j;
  for(i = 0, j = length - 1; i < j; i++, j--) {
    temp[i] = str1[j];
    temp[j] = str1[i];
  }
  temp[length] = '\0';
  printf("Reversed string: %s\n", temp);

  // convert all lowercase characters to uppercase
  for(i = 0; i < length; i++) {
    if(str1[i] >= 'a' && str1[i] <= 'z') {
      str1[i] = str1[i] - 32;
    }
  }
  printf("Uppercase string: %s\n", str1);

  // check if a substring is present in the string
  char substring[20];
  printf("Enter a substring to search: ");
  scanf("%s", substring);

  if(strstr(str1, substring) != NULL) {
    printf("Substring '%s' found in string '%s'\n", substring, str1);
  } else {
    printf("Substring not found\n");
  }

  return 0;
}