//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: cheerful
#include<stdio.h>

int main() {

  printf("Hi there! Welcome to User Input Sanitizer - a program that keeps your input clean and shiny!\n");
  
  char input[50];
  printf("Please input a string with a special character: ");
  scanf("%s", input);
  
  int i = 0;
  while (input[i] != '\0') {
    if (input[i] == '&' || input[i] == '<' || input[i] == '>'){
      input[i] = '_';
    }
    i++;
  }
  
  printf("Your sanitized input is: %s\n", input);
  
  printf("Let's try another one! Please input any string: ");
  scanf("%s", input);
  
  i = 0;
  while (input[i] != '\0') {
    if (input[i] == '$' || input[i] == '^' || input[i] == '@'){
      input[i] = '-';
    }
    i++;
  }
  
  printf("Your sanitized input is: %s\n", input);
  
  printf("Thanks for using User Input Sanitizer! We hope to see you again soon!\n");
  
  return 0;

}