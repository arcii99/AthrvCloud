//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// function to sanitize user input and remove characters that are not alphanumeric
void sanitize(char* input){
  char* sanitized = input;
  while(*input){
    if(isalnum(*input)){
      *sanitized++ = *input++;
    }else{
      input++;
    }
  }
  *sanitized = '\0';
  return;
}

int main(){
  char input[256];
  printf("Welcome to the Retro User Input Sanitizer Program!\n");
  printf("Please enter a string to be sanitized:");
  fgets(input,256,stdin);
  printf("\nYou entered: %s\n",input);
  sanitize(input);
  printf("Sanitized input: %s\n",input);
  
  return 0;
}