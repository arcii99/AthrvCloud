//FormAI DATASET v1.0 Category: Table Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  int count, num_players, player_score[4] = {0};
  char player_names[4][20] = {"Player 1", "Player 2", "Player 3", "Player 4"};
  //Four players can play this game
  srand(time(NULL)); //generating random seed
  printf("Welcome to the C-Table Game!\n");
  printf("Enter the number of players (2-4): ");
  scanf("%d", &num_players);
  if(num_players < 2 || num_players > 4){
    printf("Sorry, we cannot play with %d players. So why don't you play hide and seek instead?\n",num_players);
    exit(0); //Terminating the program if invalid number of players given
  }
  printf("Good news! We have %d players.\n", num_players);
  printf("Each player will roll the dice %d times.\n", num_players*10); //each player rolls dice 10 times
  
  for(count = 1; count <= num_players*10; count++){
    int player_index = count % num_players; //calculating player index based on roll count
    int roll = rand()%6 + 1; //generating a random number between 1 and 6
    printf("%s rolled a %d.\n", player_names[player_index], roll);
    player_score[player_index] += roll; //adding the roll to the player's score
    if(player_score[player_index] > 50){ //game ends when score crosses 50
      printf("Game Over! %s is the winner with a score of %d.\n", player_names[player_index], player_score[player_index]);
      exit(0);
    }
  }
  printf("End of game, no winner. Please play again.\n");
  return 0; //successful program execution
}