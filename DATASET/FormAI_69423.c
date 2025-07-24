//FormAI DATASET v1.0 Category: Syntax parsing ; Style: decentralized
#include <stdio.h>

void lexer(char *input) {
  char *token;
  token = strtok(input, " ");
  while(token != NULL) {
    printf("%s\n", token);
    token = strtok(NULL, " ");
  }
}

void parser(char *input[]) {

  int i = 0;

  while(input[i] != NULL) {

    if(strcmp(input[i], "for") == 0) {
      i++;
      if(input[i][0] == '(') {
        i++;
        if(strstr(input[i], ";")) {
          break;
        }
        else {
          printf("ERROR: Invalid for loop declaration\n");
        }
      }
    }

    i++;
  }

}

int main() {

  char input[100];

  printf("Enter C Syntax:\n");

  fgets(input, 100, stdin);

  printf("Tokenizing input:\n");

  lexer(input);

  printf("Parsing input:\n");

  char *token;
  token = strtok(input, " ");
  char *tokens[100];
  int i = 0;
  while(token != NULL) {
    tokens[i] = token;
    token = strtok(NULL, " ");
    i++;
  }

  tokens[i] = NULL;

  parser(tokens);

  return 0;
}