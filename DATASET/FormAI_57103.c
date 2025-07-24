//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

void sanitize_input(char *input){
  //Create a new string to store the sanitized input
  char sanitized_input[MAX_LEN];

  int j = 0;
  for(int i = 0; input[i] != '\0'; i++){
    if(isalpha(input[i])){
      //Check if character is alphabetic
      sanitized_input[j] = tolower(input[i]);
      j++;
    }else if(isdigit(input[i])){
      //Check if character is a digit
      sanitized_input[j] = input[i];
      j++;
    }
  }

  //Null terminate the sanitized input
  sanitized_input[j] = '\0';

  //Copy the sanitized input back to original input
  memcpy(input, sanitized_input, MAX_LEN);
}

int main(){
  char input[MAX_LEN];
  
  //Prompt user for input
  printf("Enter your input: ");
  fgets(input, MAX_LEN, stdin);

  //Remove trailing newline character
  input[strcspn(input, "\n")] = '\0';

  //Sanitize the input
  sanitize_input(input);

  printf("Sanitized input: %s\n", input);

  return 0;
}