//FormAI DATASET v1.0 Category: Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  char input[50];
  int choice;
  int i, j;
  char charChoice;
  int numChoice;

  printf("Welcome to the Complex Game Example Program!\n");
  printf("Please enter your name: ");
  fgets(input, 50, stdin);

  printf("\nHello, %s", input);

  printf("\n\nPlease choose a game to play:");
  printf("\n1. Tic Tac Toe");
  printf("\n2. Hangman");
  printf("\n3. Rock, Paper, Scissors");

  printf("\n\nEnter choice: ");
  fgets(input, 50, stdin);
  sscanf(input, "%d", &choice);

  switch (choice) {
    case 1:
      printf("\nTic Tac Toe selected!\n");
      // Tic Tac Toe game code goes here
      break;
    case 2:
      printf("\nHangman selected!\n");
      // Hangman game code goes here
      break;
    case 3:
      printf("\nRock, Paper, Scissors selected!\n");
      // Rock, Paper, Scissors game code goes here
      break;
    default:
      printf("\nInvalid choice!\n");
      break;
  }

  return 0;
}