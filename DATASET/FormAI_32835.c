//FormAI DATASET v1.0 Category: Syntax parsing ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
  IDENTIFIER,
  KEYWORD,
  OPERATOR,
  LITERAL
} token_type_t;

typedef struct {
  token_type_t type;
  char* value;
} token_t;

void tokenize(char* input) {
  int i=0, j=0, len=strlen(input);
  token_t* tokens = malloc(sizeof(token_t) * len);
  
  while (i < len) {
    if (isalpha(input[i])) {
      // Starting from an alphabet, identify identifier or keyword
      j = i+1;
      while (j < len && isalnum(input[j])) j++;
      
      char* value = malloc(sizeof(char) * (j-i+1));
      strncpy(value, &input[i], j-i);
      value[j-i] = '\0';
      
      if (strcmp("if", value) == 0 || strcmp("else", value) == 0 || strcmp("while", value) == 0) {
        tokens[i].type = KEYWORD;
      } else {
        tokens[i].type = IDENTIFIER;
      }
      
      tokens[i].value = value;
      i = j;
      
    } else if (isdigit(input[i])) {
      // Starting from a digit, identify number
      j = i+1;
      while (j < len && isdigit(input[j])) j++;
      
      char* value = malloc(sizeof(char) * (j-i+1));
      strncpy(value, &input[i], j-i);
      value[j-i] = '\0';
      
      tokens[i].type = LITERAL;
      tokens[i].value = value;
      i = j;
      
    } else if (strchr("+-*/=", input[i]) != NULL) {
      // Identify operator
      tokens[i].type = OPERATOR;
      tokens[i].value = malloc(2);
      tokens[i].value[0] = input[i];
      tokens[i++].value[1] = '\0';
      
    } else {
      // Skip if not recognized
      i++;
    }
  }
  
  // Print the tokens
  for (int i=0; i<len; i++) {
    printf("%s (%d)\n", tokens[i].value, tokens[i].type);
    free(tokens[i].value);
  }
  free(tokens);
}

int main() {
  char input[] = "if (x > 5) y = 10; else y = -10;";
  tokenize(input);
  return 0;
}