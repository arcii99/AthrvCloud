//FormAI DATASET v1.0 Category: Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the craziest game ever!\n");
  printf("Are you ready to play?\n");
  printf("Enter your name: ");

  char name[20];
  scanf("%s", name);
  
  printf("Welcome %s, let's start the game!\n", name);
  printf("In this game, you will be controlling a flying unicorn. Yes, you heard it right, a unicorn!\n");
  printf("Use the arrow keys to move around and collect all the magical stars to win the game.\n");
  printf("But beware, there are evil witches on their brooms who will try to knock you down.\n");
  printf("If you hit them, you will lose some of your powers, so be careful.\n");
  
  printf("Press enter to start the game.\n");
  getchar();

  int score = 0;
  int lives = 3;
  int powers = 100;
  
  while (lives > 0 && powers > 0) {
    printf("Score: %d, Lives: %d, Powers: %d\n", score, lives, powers);
    printf("Collect stars to increase your score.\n");

    // Code for controlling the unicorn

    // Code for moving the witches on their brooms

    // Code for collision detection

    // Code for updating scores, lives, and powers

    // Code for displaying the game over screen
  }

  printf("Game over! Your final score is %d.\n", score);
  printf("Thanks for playing, come back soon!\n");

  return 0;
}