//FormAI DATASET v1.0 Category: Checkers Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

typedef enum{ Empty, Black, White } Piece; // Define the 3 types of pieces on the board
Piece board[8][8]; // 8x8 board for checkers game

typedef struct { int x; int y; } Position; // Define the Position struct

Piece getPiece(Position pos) { // Get a piece from the board at a given position
  if((pos.x < 0) || (pos.x > 7) || (pos.y < 0) || (pos.y > 7)) return Empty; // Return Empty if the position is out of the board
  return board[pos.y][pos.x];
}

void setPiece(Position pos, Piece piece) { // Set a piece on the board at a given position
  if((pos.x < 0) || (pos.x > 7) || (pos.y < 0) || (pos.y > 7)) return; // Do nothing if the position is out of the board
  board[pos.y][pos.x] = piece;
}

Position getPosition(char* input) { // Get the position from a string input, e.g. "A1"
  Position pos;
  pos.x = input[0] - 'A'; // Convert the column letter to a number
  pos.y = input[1] - '1'; // Convert the row number to a number
  return pos;
}

void printBoard() { // Print the checkers board
  printf("\n  A B C D E F G H\n");
  for(int y = 0; y < 8; y++) {
    printf("%d ", y+1);
    for(int x = 0; x < 8; x++) {
      switch(getPiece((Position){x,y})) {
        case Empty: printf(". "); break;
        case Black: printf("B "); break;
        case White: printf("W "); break;
      }
    }
    printf("%d", y+1);
    printf("\n");
  }
  printf("  A B C D E F G H\n\n");
}

void resetBoard() { // Reset the checkers board to the starting position
  for(int y = 0; y < 8; y++) {
    for(int x = 0; x < 8; x++) {
      if((y <= 2) && ((x+y)%2 == 1)) setPiece((Position){x,y}, Black); // Set the black pieces on the top
      else if((y >= 5) && ((x+y)%2 == 1)) setPiece((Position){x,y}, White); // Set the white pieces on the bottom
      else setPiece((Position){x,y}, Empty); // Set the empty spaces in the middle
    }
  }
}

int main() {
  resetBoard(); // Reset the board to the starting position
  printBoard(); // Print the board to start the game
  
  return 0;
}