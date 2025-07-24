//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // seed random number generator
  int i, j;
  char house[4][30] = { 
    "##########################",
    "#........................#",
    "#......#####.............#",
    "#..........#.............#"
  };
  int player_row = 3;
  int player_col = 15;
  int ghost_row = 1;
  int ghost_col = rand() % 28 + 1; // place ghost randomly
  int score = 0;

  printf("Welcome to the Haunted House simulator!\n");
  printf("Navigate through the house with the arrow keys and try to collect all the gold.\n");
  printf("Be careful though, there's a ghost lurking around!\n\n");

  while (1) {
    system("clear"); // clear console
    for (i = 0; i < 4; i++) {
      for (j = 0; j < 30; j++) {
        if (i == player_row && j == player_col) {
          printf("P"); // print player
        } else if (i == ghost_row && j == ghost_col) {
          printf("G"); // print ghost
        } else {
          printf("%c", house[i][j]); // print house
        }
      }
      printf("\n");
    }
    printf("Score: %d\n", score);

    char move = getchar();
    switch (move) {
      case 'w':
        if (player_row > 0 && house[player_row-1][player_col] != '#') {
          player_row--;
        }
        break;
      case 'a':
        if (player_col > 0 && house[player_row][player_col-1] != '#') {
          player_col--;
        }
        break;
      case 's':
        if (player_row < 3 && house[player_row+1][player_col] != '#') {
          player_row++;
        }
        break;
      case 'd':
        if (player_col < 29 && house[player_row][player_col+1] != '#') {
          player_col++;
        }
        break;
    }

    if (ghost_col < player_col) {
      ghost_col++;
    } else if (ghost_col > player_col) {
      ghost_col--;
    }
    if (ghost_row < player_row) {
      ghost_row++;
    } else if (ghost_row > player_row) {
      ghost_row--;
    }

    // check if player has collected gold
    if (house[player_row][player_col] == '.') {
      house[player_row][player_col] = ' ';
      score++;
    }

    // check if player has hit a ghost
    if (player_row == ghost_row && player_col == ghost_col) {
      printf("You were caught by the ghost and died!\n");
      printf("Final score: %d\n", score);
      return 0;
    }

    // check if player has collected all the gold
    if (score == 5) {
      printf("Congratulations, you collected all the gold and escaped the haunted house!\n");
      return 0;
    }
  }
}