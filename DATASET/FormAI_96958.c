//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: synchronous
#include <stdio.h>
#include <string.h>

int main()
{
  char english[100];
  printf("Enter a word in English: ");
  scanf("%s", english);

  // Translate the word into alien language
  for (int i = 0; i < strlen(english); i++) {
    english[i] += 10; // Add 10 to each ASCII character code
  }

  printf("The word in alien language is: %s\n", english);

  return 0;
}