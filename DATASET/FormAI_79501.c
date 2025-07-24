//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); //initialize random seed

  char question[100];
  printf("Welcome to the Automated Fortune Teller. Ask a Yes/No question and I'll predict your future!\n");
  
  printf("What is your question?\n");
  fgets(question, 100, stdin); //get user input

  int answer = rand() % 2; //generate random number 0 or 1

  if(answer == 0) {
    printf("The answer to your question '%s' is Yes.\n", question);
  }
  else {
    printf("The answer to your question '%s' is No.\n", question);
  }

  return 0;
}