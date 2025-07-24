//FormAI DATASET v1.0 Category: Table Game ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* Function to generate random number from 1 to 6 */
int getDiceValue(){
  int diceValue;
  srand(time(0));
  diceValue = rand()%6+1;
  return diceValue;
}

int main(){
  int position[100], playerCount, curPlayer = 0, maxPlayers = 4, n = 100;
  /* Initialising positions of all players as 0 */
  for(int i=0;i<n;i++){
    position[i] = 0;
  }
  printf("Enter number of players: ");
  scanf("%d", &playerCount);

  /* Minimum of 2 and maximum of 4 players are allowed */
  if(playerCount<2 || playerCount>4){
    printf("Invalid number of players entered. Please enter between 2 to 4 players.\n");
    exit(0);
  }
  printf("\n\nLet's have fun! Starting game for %d player%s.\n", playerCount, playerCount>1?"s":"");
  
  /* Main game loop begins */
  while(1){
    printf("\n\nIt's Player %d's turn.\n", curPlayer+1);
    printf("Press any key to roll the dice....\n");
    getchar();
    
    /* Generate dice value from 1 to 6 */
    int diceValue = getDiceValue();
    printf("\nPlayer %d got %d on dice.\n", curPlayer+1, diceValue);

    /* Add the dice value to current player's position */
    position[curPlayer] += diceValue;

    /* Check if the player reached the final position */
    if(position[curPlayer] >= n){
      printf("\n\nCongratulations!! Player %d wins the game.\n\n", curPlayer+1);
      exit(0);
    }
    
    /* Print current positions of all players */
    printf("\nCurrent positions:\n");
    for(int i=0;i<playerCount;i++){
      printf("Player %d: %d\n", i+1, position[i]);
    }

    /* Check for certain snakes or ladders */
    switch(position[curPlayer]){
      case 5:
        position[curPlayer] = 27; // Snake
        printf("\nOops! Player %d got bitten by a snake and landed at position 27.\n", curPlayer+1);
        break;

      case 13:
        position[curPlayer] = 47; // Ladder
        printf("\nWohoo!! Player %d found a ladder and climbed to position 47.\n", curPlayer+1);
        break;

      case 21:
        position[curPlayer] = 9; // Snake
        printf("\nOops! Player %d got bitten by a snake and landed at position 9.\n", curPlayer+1);
        break;

      case 42:
        position[curPlayer] = 63; // Ladder
        printf("\nWohoo!! Player %d found a ladder and climbed to position 63.\n", curPlayer+1);
        break;

      case 50:
        position[curPlayer] = 68; // Ladder
        printf("\nWohoo!! Player %d found a ladder and climbed to position 68.\n", curPlayer+1);
        break;

      case 66:
        position[curPlayer] = 98; // Ladder
        printf("\nWohoo!! Player %d found a ladder and climbed to position 98.\n", curPlayer+1);
        break;

      case 85:
        position[curPlayer] = 95; // Ladder
        printf("\nWohoo!! Player %d found a ladder and climbed to position 95.\n", curPlayer+1);
        break;

      case 99:
        position[curPlayer] = 69; // Snake
        printf("\nOops! Player %d got bitten by a snake and landed at position 69.\n", curPlayer+1);
        break;

      default:
        break;
    }

    /* Switch to next player */
    curPlayer++;
    if(curPlayer == playerCount){
      curPlayer = 0;
    }
  }

  return 0;
}