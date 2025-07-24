//FormAI DATASET v1.0 Category: Table Game ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

   int player_1_score = 0, player_2_score = 0;
   int player_1_turn = 0, player_2_turn = 0;
   int dice_roll, round;

   printf("Welcome to the epic C Table Game!\n\n");

   srand(time(0));

   for(round = 1; round <= 3; round++){

      printf("Round %d starts now! May the best player win!\n\n", round);

      for(player_1_turn = 1; player_1_turn <= 5; player_1_turn++){

         printf("Player 1, it's your turn! Press enter to roll the dice.\n");
         getchar();  // wait for user to press enter
         
         dice_roll = rand() % 6 + 1;  // roll the dice
         printf("You rolled a %d!\n", dice_roll);

         if(dice_roll == 1){
            printf("Oops, you rolled a 1. Your turn is over.\n\n");
            continue;  // go to next iteration of the loop
         }

         player_1_score += dice_roll;  // add to player 1's score
         printf("Your current score is %d! Keep going!\n\n", player_1_score);

      }

      printf("Player 1's turn is over! Your score for round %d is %d.\n\n", round, player_1_score);

      for(player_2_turn = 1; player_2_turn <= 5; player_2_turn++){

         printf("Player 2, it's your turn! Press enter to roll the dice.\n");
         getchar();  // wait for user to press enter

         dice_roll = rand() % 6 + 1;  // roll the dice
         printf("You rolled a %d!\n", dice_roll);

         if(dice_roll == 1){
            printf("Oops, you rolled a 1. Your turn is over.\n\n");
            continue;  // go to next iteration of the loop
         }

         player_2_score += dice_roll;  // add to player 2's score
         printf("Your current score is %d! Keep going!\n\n", player_2_score);

      }

      printf("Player 2's turn is over! Your score for round %d is %d.\n\n", round, player_2_score);

   }

   printf("\n\nGAME OVER! Final score:\n");
   printf("Player 1: %d\n", player_1_score);
   printf("Player 2: %d\n", player_2_score);

   if(player_1_score > player_2_score){
      printf("Player 1 wins! Congratulations!\n");
   } else if(player_2_score > player_1_score){
      printf("Player 2 wins! Congratulations!\n");
   } else {
      printf("It's a tie! Better luck next time!\n");
   }

   return 0;

}