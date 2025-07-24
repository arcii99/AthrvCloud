//FormAI DATASET v1.0 Category: Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int player1_x, player1_y, player2_x, player2_y;
  int treasure_x, treasure_y;
  int board_size = 8;
  srand(time(NULL));
  
  // Initialize players and treasure positions randomly
  player1_x = rand() % board_size;
  player1_y = rand() % board_size;
  player2_x = rand() % board_size;
  player2_y = rand() % board_size;
  treasure_x = rand() % board_size;
  treasure_y = rand() % board_size;
  
  printf("Welcome to the treasure hunt game!\n");
  printf("Player 1: (%d, %d)\n", player1_x, player1_y);
  printf("Player 2: (%d, %d)\n", player2_x, player2_y);
  printf("Treasure: (%d, %d)\n", treasure_x, treasure_y);
  
  // Main game loop
  while (1) {
    // Player 1's turn
    printf("Player 1's turn\n");
    printf("Enter x coordinate: ");
    scanf("%d", &player1_x);
    printf("Enter y coordinate: ");
    scanf("%d", &player1_y);
    if (player1_x == treasure_x && player1_y == treasure_y) {
      printf("Player 1 found the treasure and wins the game!\n");
      break;
    }
    
    // Player 2's turn
    printf("Player 2's turn\n");
    printf("Enter x coordinate: ");
    scanf("%d", &player2_x);
    printf("Enter y coordinate: ");
    scanf("%d", &player2_y);
    if (player2_x == treasure_x && player2_y == treasure_y) {
      printf("Player 2 found the treasure and wins the game!\n");
      break;
    }
  }
  return 0;
}