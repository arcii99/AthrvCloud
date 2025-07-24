//FormAI DATASET v1.0 Category: Memory Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   // Initialize random number generator seed
   srand(time(NULL));
   
   // Declare array of 16 integers to represent the memory board
   int board[16];
   
   // Populate board with random numbers between 1 and 8
   for (int i = 0; i < 16; i++) {
      board[i] = rand() % 8 + 1;
   }
   
   // Declare array of 16 booleans to represent which cards have been guessed correctly
   int guessed[16] = {0};
   
   // Declare variables to keep track of turns and score
   int turns = 0;
   int score = 0;
   
   // Print instructions
   printf("Welcome to the Memory Game!\n");
   printf("You will see a 4x4 board with hidden numbers from 1 to 8.\n");
   printf("You must choose two cards at a time and try to match them.\n");
   printf("You win when you have matched every pair of cards.\n");
   
   // Main game loop
   while (score < 8) {
      // Print the board
      printf("\nTURN %d\n", turns+1);
      for (int i = 0; i < 16; i++) {
         if (guessed[i]) {
            printf("%2d ", board[i]);
         } else {
            printf("%2d ", i+1);
         }
         if ((i+1) % 4 == 0) {
            printf("\n");
         }
      }
      
      // Get the positions of the two cards the user wants to flip
      int pos1, pos2;
      printf("Enter the first card position (1-16): ");
      scanf("%d", &pos1);
      printf("Enter the second card position (1-16): ");
      scanf("%d", &pos2);
      
      // Verify the user entered valid positions and that the two cards are not already guessed
      if (pos1 < 1 || pos1 > 16 || pos2 < 1 || pos2 > 16 || guessed[pos1-1] || guessed[pos2-1] || pos1 == pos2) {
         printf("Invalid input, please try again.\n");
         continue;
      }
      
      // Flip the two cards
      guessed[pos1-1] = 1;
      guessed[pos2-1] = 1;
      
      // Check if the two cards match
      if (board[pos1-1] == board[pos2-1]) {
         score++;
         printf("Match!\n");
      } else {
         printf("No match.\n");
      }
      
      // Increment the number of turns
      turns++;
   }
   
   // Game over
   printf("\nCongratulations, you win!\n");
   printf("You completed the memory game in %d turns.\n", turns);
   
   return 0;
}