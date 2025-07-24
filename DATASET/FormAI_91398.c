//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: irregular
#include <stdio.h>

int main() {

  char input[] = "Meow meow meow!";

  printf("Input: %s\n\n", input);
  
  int length = strlen(input); //gets length of input
  
  printf("Output: ");
  
  for (int i = 0; i < length; i++) {
    
    if (input[i] == 'M' || input[i] == 'm') {
      
      printf("Meow! "); //translates M or m to Meow!
      
    } else {
      
      printf("Purr. "); //translates all other characters to Purr.
      
    }
    
  }
  
  printf("\n");
  
  return 0;
}