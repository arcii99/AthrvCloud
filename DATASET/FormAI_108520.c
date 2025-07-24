//FormAI DATASET v1.0 Category: Word Count Tool ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  printf("I can't believe it! I have never seen such a crazy Code Count Tool before!\n\n");
  printf("Please enter your code below:\n");

  char code[150000];

  fgets(code, 150000, stdin);
  
  int count = 0;
  int is_word = 0;

  for(int i = 0; i < strlen(code); i++) {

    if(code[i] == ' ' || code[i] == '\n' || code[i] == '\r' || code[i] == '\t' || code[i] == '\0') {
    
      is_word = 0;
    
    } else {
      
      if(is_word == 0) {
        count++;
        is_word = 1;
      }
      
    }

  }

  printf("\nOMG! Your code has %d words in it!\n", count);

  return 0;

}