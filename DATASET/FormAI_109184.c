//FormAI DATASET v1.0 Category: Table Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // Setting the seed for random number generation
  
  int p1_score = 0, p2_score = 0; // Initializing scores
  
  printf("Welcome to the wackiest table game you'll ever play!\n");
  printf("Each player will take turns rolling the dice until they reach a score of 50.\n");
  printf("However, there's a catch!\n");
  printf("If you roll a number that's divisible by 3, you'll lose your turn!\n");
  printf("And if you roll a number that's a multiple of 7, your score will be reset to 0!\n");
  printf("Let's begin!\n\n");
  
  int current_player = 1; // Initializing current player to player 1
  
  while (p1_score < 50 && p2_score < 50) { // Keep playing until one player reaches a score of 50
    int roll = rand() % 6 + 1; // Generating a random number between 1 and 6
    
    printf("Player %d, it's your turn!\n", current_player);
    printf("You rolled a %d!\n", roll);
    
    if (roll % 3 == 0) { // Check if the number is divisible by 3
      printf("Oh no, you rolled a number that's divisible by 3! You lose your turn.\n\n");
    } else if (roll % 7 == 0) { // Check if the number is a multiple of 7
      printf("Woopsie, you rolled a number that's a multiple of 7! Your score is reset to 0.\n\n");
      if (current_player == 1) {
        p1_score = 0;
      } else {
        p2_score = 0;
      }
    } else { // Add the roll to the player's score
      if (current_player == 1) {
        p1_score += roll;
      } else {
        p2_score += roll;
      }
      printf("Your current score is %d.\n\n", current_player == 1 ? p1_score : p2_score);
    }
    
    // Switch to the other player
    current_player = current_player == 1 ? 2 : 1;
  }
  
  printf("Congratulations Player %d, you won with a score of %d!\n", p1_score > p2_score ? 1 : 2, p1_score > p2_score ? p1_score : p2_score);
  printf("Thanks for playing the wackiest table game ever!");
  
  return 0;
}