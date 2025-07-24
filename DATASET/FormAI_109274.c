//FormAI DATASET v1.0 Category: Word Count Tool ; Style: funny
#include <stdio.h>

int main() {
  char message[100];
  int count=0;
  
  printf("Welcome to the Crazy C Word Counter!\n");
  printf("Please enter a message to count the words in it: \n");
  fgets(message, 100, stdin);

  for(int i=0; message[i] !='\0'; i++) {
    if(message[i] == ' ') {
      count++;
    }
  }
  count++;

  printf("\nCongratulations, you entered %d words into the program!\n", count);
  printf("I guess that makes you pretty good at typing things out, huh?\n");

  return 0;
}