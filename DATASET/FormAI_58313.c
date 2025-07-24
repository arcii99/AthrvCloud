//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void parse(char *input){
  int i = 0, j = 0;
  char token[50];

  printf("Parsing input: %s\n", input);

  for(i = 0; i < strlen(input);){
    // Ignore spaces
    if(input[i] == ' '){
      i++;
      continue;
    }

    // Check for integer
    if(input[i] >= '0' && input[i] <= '9'){
      j = 0;

      while(input[i] >= '0' && input[i] <= '9'){
        token[j] = input[i];
        j++;
        i++;
      }

      token[j] = '\0';
      printf("Found integer: %s\n", token);
      continue;
    }

    // Check for operator or delimiter
    if(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == ';' || input[i] == '(' || input[i] == ')'){
      token[0] = input[i];
      token[1] = '\0';
      printf("Found operator or delimiter: %s\n", token);
      i++;
      continue;
    }

    // Check for identifier
    if((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z')){
      j = 0;

      while((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= '0' && input[i] <= '9')){
        token[j] = input[i];
        j++;
        i++;
      }

      token[j] = '\0';
      printf("Found identifier: %s\n", token);
      continue;
    }

    printf("Invalid character found: %c\n", input[i]);
    i++;
  }
}

int main(){
  char input[100];

  printf("Enter C code to be parsed:\n");
  fgets(input, 100, stdin);

  parse(input);

  return 0;
}