//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
  char input[1000];
  printf("Welcome to the User Input Sanitizer!\n");
  printf("Please enter the text that needs to be sanitized (no more than 1000 characters):\n");
  fgets(input, sizeof(input), stdin);
  
  // Removing any unwanted characters
  for(int i=0; i<strlen(input); i++) {
    if(input[i] == '$' || input[i] == '#' || input[i] == '@') {
      input[i] = ' ';  // Simply replacing with space because this is a user-sanitizer program, not a code executor!
    }
    else if(!isalpha(input[i]) && !isspace(input[i])) {
      input[i] = '_';
    }
  }
  
  printf("\n\nHere is your sanitized input: \n");
  printf("%s", input);
  printf("\n\n");
  
  printf("Now that was fun! Want to sanitize more inputs? (yes/no)\n");
  char answer[5];
  fgets(answer, sizeof(answer), stdin);
  if(strcmp(answer, "yes\n") == 0 || strcmp(answer, "Yes\n") == 0 || strcmp(answer, "YES\n") == 0) {
    system("clear");  // For fun, let's clear the console first
    main();  // Recursive fun time!
  }
  else if(strcmp(answer, "no\n") == 0 || strcmp(answer, "No\n") == 0 || strcmp(answer, "NO\n") == 0) {
    printf("Alrighty then, have a nice day!\n");
  }
  else {
    printf("I'm sorry, I didn't understand your response. Please try again next time!\n");
  }
  
  return 0;
}