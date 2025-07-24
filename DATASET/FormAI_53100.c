//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void sanitize(char **str);

int main() 
{
  char *input = NULL;

  printf("Enter a string: ");
  getline(&input, NULL, stdin);

  printf("\nOriginal input: %s", input);

  sanitize(&input);

  printf("\nSanitized input: %s", input);

  free(input);
  return 0;
}

void sanitize(char **str)
{
  char *sanitized = (char*)malloc(sizeof(char) * strlen(*str) + 1);
  int j = 0;

  for(int i=0; i<strlen(*str); i++) {
    if((*str)[i] != '\n') {
      if(isalpha((*str)[i]) || isdigit((*str)[i]) || isspace((*str)[i])) {
        sanitized[j] = (*str)[i];
        j++;
      }
    }
  }
  sanitized[j] = '\0';

  *str = (char*)realloc(*str, sizeof(char) * strlen(sanitized) + 1);
  strcpy(*str, sanitized);

  free(sanitized);
}