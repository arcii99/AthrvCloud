//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char name[20];
  char question[100];
  
  printf("Welcome to the Automated Fortune Teller program!\n");
  printf("What is your name?\n");
  scanf("%s", name);
  
  printf("Hello, %s! Please enter your yes or no question:\n", name);
  scanf(" %[^\n]s", question);
  printf("Thinking...\n");

  srand(time(NULL));
  int random_num = rand() % 10;

  if (random_num == 0) {
    printf("The answer is yes.\n");
  } else if (random_num == 1) {
    printf("The answer is no.\n");
  } else if (random_num == 2) {
    printf("It is certain.\n");
  } else if (random_num == 3) {
    printf("Reply hazy, try again.\n");
  } else if (random_num == 4) {
    printf("Better not tell you now.\n");
  } else if (random_num == 5) {
    printf("Concentrate and ask again.\n");
  } else if (random_num == 6) {
    printf("My sources say no.\n");
  } else if (random_num == 7) {
    printf("Outlook not so good.\n");
  } else if (random_num == 8) {
    printf("Very doubtful.\n");
  } else if (random_num == 9) {
    printf("Ask again later.\n");
  } else {
    printf("Error: Invalid random number generated.\n");
  }

  return 0;
}