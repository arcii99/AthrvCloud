//FormAI DATASET v1.0 Category: Word Count Tool ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {

  char sentence[100];       // maximum length of sentence is 100 characters
  int counter = 1;          // starting the counter at 1 to account for the first word
  int i;

  printf("Please enter your sentence: \n");
  fgets(sentence, 100, stdin);    // using fgets to get the whole sentence

  for (i=0; sentence[i] != '\0'; i++){   
    if(isspace(sentence[i])){     // checking if the character is a space
      counter++;                  // incrementing counter for each space
    }
  }

  printf("Your sentence has %d words!\n", counter);
  return 0;
}