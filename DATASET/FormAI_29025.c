//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: careful
#include <stdio.h>
#include <string.h>

int main()
{
  char c1[] = "khchf";
  char c2[] = "cksce";

  printf("Enter the alien word: ");

  char user_input[20];
  scanf("%s", user_input);

  if (strcmp(user_input, c1) == 0)
  {
      printf("The translation is: Hello\n");
  }
  else if (strcmp(user_input, c2) == 0)
  {
      printf("The translation is: Goodbye\n");
  }
  else
  {
      printf("The translation for this word is not found in the dictionary.\n");
  }

  return 0;
}