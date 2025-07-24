//FormAI DATASET v1.0 Category: Random ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char *name;
  int age;
  int r;
  
  printf("What is your name?\n");
  scanf("%s", name);
  
  printf("Hello %s! How old are you?\n", name);
  scanf("%d", &age);
  
  printf("Okay, let's play a game. I'm thinking of a number between 1 and 10. You have to guess it.\n");
  
  srand(time(0));
  r = rand() % 10 + 1;
  
  printf("Guess the number: ");
  int guess;
  scanf("%d", &guess);
  
  int attempts = 1;
  while (guess != r) {
    printf("Sorry, that's not correct. Try again: ");
    scanf("%d", &guess);
    attempts++;
  }
  
  printf("Congratulations %s! You guessed the number in %d attempts.\n", name, attempts);
  
  return 0;
}