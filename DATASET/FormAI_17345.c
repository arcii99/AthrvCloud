//FormAI DATASET v1.0 Category: String manipulation ; Style: high level of detail
#include <stdio.h>
#include <string.h>

int main(void)
{
  char string1[40], string2[40];
  char concat[80];
  int len;
 
  printf("Enter a string (maximum 40 characters) : \n");
  scanf("%s", string1);//taking user input

  printf("\nEnter another string (maximum 40 characters) : \n");
  scanf("%s", string2);//taking user input

  // length of string1
  len = strlen(string1);
  printf("\nLength of first string is %d\n", len);

  // length of string2
  len = strlen(string2);
  printf("Length of second string is %d\n", len);

  // comparison of two strings
  if(strcmp(string1, string2) == 0)
    printf("\nEntered strings are equal.\n");
  else
    printf("\nEntered strings are not equal.\n");

  // concatenation of two strings
  strcpy(concat, string1);
  strcat(concat, string2);
  printf("\nConcatenated string is : %s\n", concat);

  return 0;
}