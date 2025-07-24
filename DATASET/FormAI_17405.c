//FormAI DATASET v1.0 Category: Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

int main() {

  printf("Welcome to the Happy Game!\n");
  printf("In this game, you will input your lucky number and battle against the computer!\n");
  printf("Enter a number between 1 and 100: ");

  srand(time(NULL));
  int computerNum = rand() % 100;
  int playerNum;
  int roundCounter = 1;

  scanf("%d", &playerNum);

  while (playerNum != computerNum) {
    if (playerNum > computerNum) {
      printf("Too high! Try again: ");
    } else {
      printf("Too low! Try again: ");
    }

    scanf("%d", &playerNum);
    roundCounter++;
  }

  printf("Congratulations! You win in %d rounds!\n", roundCounter);

  return 0;
}