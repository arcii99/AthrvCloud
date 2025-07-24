//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 10

int main(void) {

  char aliens[ROWS][COLS];
  char ship[COLS];
  int score = 0;
  int lives = 3;
  int pos = 4;
  int alien_count = ROWS * COLS;

  srand(time(NULL));

  //Initialize aliens
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      aliens[i][j] = 'O';
    }
  }

  //Initialize ship
  for (int i = 0; i < COLS; i++) {
    ship[i] = '-';
  }
  ship[pos] = '*';

  //Game Loop
  do {
    //Print Screen
    system("clear"); //UNIX
    printf("SCORE: %d\tLIVES: %d\n\n", score, lives);
    for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
        printf("%c ", aliens[i][j]);
      }
      printf("\n");
    }
    for (int i = 0; i < COLS; i++) {
      printf("%c", ship[i]);
    }
    printf("\n\nPress 'a' to move left, 'd' to move right, and 'space' to fire.\n");

    //Check for Input
    char input;
    scanf("%c", &input);
    getchar(); //Removes newline character from input buffer

    //Process Input
    if (input == 'a') { //Move left
      if (pos > 0) {
        ship[pos] = '-';
        pos--;
        ship[pos] = '*';
      }
    } else if (input == 'd') { //Move right
      if (pos < COLS - 1) {
        ship[pos] = '-';
        pos++;
        ship[pos] = '*';
      }
    } else if (input == ' ') { //Fire
      for (int i = ROWS - 1; i >= 0; i--) {
        if (aliens[i][pos] == 'O') {
          aliens[i][pos] = ' ';
          score += 10;
          alien_count--;
          break;
        }
      }
    }

    //Move aliens down
    for (int j = 0; j < COLS; j++) {
      if (aliens[ROWS - 1][j] == 'O') {
        lives--;
        if (lives == 0) {
          printf("GAME OVER\n");
          return 0;
        }
      }
    }
    for (int i = ROWS - 1; i > 0; i--) {
      for (int j = 0; j < COLS; j++) {
        aliens[i][j] = aliens[i - 1][j];
      }
    }
    for (int j = 0; j < COLS; j++) {
      aliens[0][j] = 'O';
    }

  } while (alien_count > 0);

  //Win Condition
  printf("YOU WIN\n");
  return 0;
}