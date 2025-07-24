//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: random
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_LENGTH 100

int main(){
  char input[MAX_LENGTH];
  printf("Enter input: ");
  fgets(input, MAX_LENGTH, stdin);
  // remove newline character at the end of input
  input[strcspn(input, "\n")] = 0;

  // check for malicious input
  int i, length = strlen(input);
  for (i = 0; i < length; i++){
    if (input[i] == '<' || input[i] == '>' || input[i] == '&' || input[i] == '|'){
      printf("Error: Invalid characters found. Exiting program.\n");
      exit(0);
    }
  }

  // sanitize input
  char sanitized_input[MAX_LENGTH];
  i = 0;
  int j = 0;
  while (input[i] != '\0'){
    if (input[i] >= 'a' && input[i] <= 'z'){ // convert lowercase letters to uppercase
      sanitized_input[j++] = input[i] - 32;
    }
    else if (input[i] >= 'A' && input[i] <= 'Z'){ // copy uppercase letters as is
      sanitized_input[j++] = input[i];
    }
    else if (input[i] >= '0' && input [i] <= '9'){ // copy numbers as is
      sanitized_input[j++] = input[i];
    }
    else if (input[i] == ' '){ // replace spaces with underscores
      sanitized_input[j++] = '_';
    }
    else{ // remove non-alphanumeric characters
      sanitized_input[j++] = '_';
    }
    i++;
  }
  sanitized_input[j] = '\0';

  printf("Sanitized input: %s\n", sanitized_input);
  return 0;
}