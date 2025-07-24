//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: portable
#include <stdio.h>
#include <string.h>

int main() {
  char input[100];
  char output[100];
  
  printf("Enter a sentence in Cat Language: ");
  fgets(input, 100, stdin);
  
  char *token;
  const char delim[2] = " ";
  int i = 0;
  
  token = strtok(input, delim);
  
  while (token != NULL) {
    if (!strcmp(token, "meow")) {
      strcpy(output+i, "A");
      i++;
    } else if (!strcmp(token, "purr")) {
      strcpy(output+i, "B");
      i++;
    } else if (!strcmp(token, "hiss")) {
      strcpy(output+i, "C");
      i++;
    } else if (!strcmp(token, "paw")) {
      strcpy(output+i, "D");
      i++;
    } else if (!strcmp(token, "tail")) {
      strcpy(output+i, "E");
      i++;
    } else if (!strcmp(token, "whisker")) {
      strcpy(output+i, "F");
      i++;
    }
    
    token = strtok(NULL, delim);
  }
  
  printf("Here is your sentence in English: %s\n", output);
  
  return 0;
}