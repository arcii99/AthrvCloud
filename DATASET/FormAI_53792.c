//FormAI DATASET v1.0 Category: Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main(){
  int playerA = 0, playerB = 0;
  int min = 1, max = 6;
  int round = 1;
  
  printf("Welcome to a game of dice!\n");
  printf("Player A goes first.\n");
  
  while(playerA < 50 && playerB < 50){
    printf("Round %d:\n", round);
    printf("Player A: ");
    playerA += (rand() % (max - min + 1)) + min;
    printf("%d     Player B: ", playerA);
    playerB += (rand() % (max - min + 1)) + min;
    printf("%d\n", playerB);
    round++;
  }
  
  if(playerA >= 50){
    printf("Player A wins!");
  }
  else{
    printf("Player B wins!");
  }
  
  return 0;
}