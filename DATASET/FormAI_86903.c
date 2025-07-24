//FormAI DATASET v1.0 Category: Word Count Tool ; Style: irregular
//Welcome to the C Word Count Tool program!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
  char input[1024];
  int count = 0;

  printf("Enter a sentence: ");
  fgets(input, 1024, stdin); //Read input from user

  //Count number of words
  for(int i = 0; i < strlen(input); i++) {
    if(input[i] == ' ' && input[i+1] != ' ') { //If current character is space and next character is not space
      count++; //Increment word count
    }
  }

  printf("\nWord Count: %d\n", count+1); //Print word count (+1 because the last word has no space after it)

  return 0; 
}