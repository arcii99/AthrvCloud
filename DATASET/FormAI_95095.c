//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: configurable
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100
#define MAX_TRANSLATION_LENGTH 50

char alienLetters[] = {'#', '$', '%', '&', '*', '+', '-', '/', '@', '^'};
char humanLetters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

void translateWord(char *word);

int main()
{
  char input[MAX_INPUT_LENGTH];

  printf("Enter a word or sentence in Alien Language:\n"); 
  fgets(input, MAX_INPUT_LENGTH, stdin);

  // Remove newline character from input
  input[strcspn(input, "\n")] = 0;

  char *token = strtok(input, " ");

  while (token != NULL)
  {
    translateWord(token);
    token = strtok(NULL, " ");
  }
}

void translateWord(char *word)
{
  for (int i = 0; i < strlen(word); i++)
  {
    for (int j = 0; j < 10; j++)
    {
      if (word[i] == alienLetters[j])
      {
        printf("%c", humanLetters[j]);
        break;
      }

      if (j == 9)
      {
        printf("*");
      }
    }
  }

  printf(" ");
}