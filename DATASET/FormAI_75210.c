//FormAI DATASET v1.0 Category: String manipulation ; Style: ephemeral
#include <stdio.h>
#include <string.h>

int main()
{
  char str1[50], str2[50], str3[50];
  int length;

  printf("Enter your first name: ");
  scanf("%s", str1);

  printf("Enter your last name: ");
  scanf("%s", str2);

  printf("Enter your favorite number: ");
  scanf("%s", str3);

  strcat(str1, " "); // Add a space between first and last name
  strcat(str1, str2); // Concatenate first and last name
  length = strlen(str1);

  printf("Hello %s, your name is %d characters long.\n", str1, length);

  if (strcmp(str3, "7") == 0) // Check if favorite number is 7
  {
    printf("Wow, we have the same favorite number!\n");
  }
  else
  {
    int num = atoi(str3); // Convert string to integer
    printf("Your favorite number multiplied by 2 is: %d\n", num * 2);
  }

  return 0;
}