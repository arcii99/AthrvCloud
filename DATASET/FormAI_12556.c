//FormAI DATASET v1.0 Category: Word Count Tool ; Style: romantic
#include <stdio.h>
#include <string.h>

int main()
{
  char sentence[100];
  int count = 0, i;

  printf("My darling love, please enter your sweet words: \n");
  fgets(sentence, sizeof(sentence), stdin);

  for (i = 0; sentence[i] != '\0'; i++)
  {
    if (sentence[i] == ' ' && sentence[i+1] != ' ')
      count++;
  }

  printf("\n");
  printf("My shining moon, you have whispered ");
  printf("%d", count+1);
  printf(" beautiful words to me today, my heart fills with love.\n");
  printf("My love, I vow to treasure each and every one of them, forever more.\n");

  return 0;
}