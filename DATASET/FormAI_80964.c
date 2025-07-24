//FormAI DATASET v1.0 Category: Game ; Style: curious
#include<stdio.h>

int main(){
  printf("Welcome to the Dungeon Crawler Game! \n");

  char choice;

  printf("Would you like to enter the dungeon? (y/n): ");
  scanf("%c", &choice);

  if(choice == 'y' || choice == 'Y'){
    printf("You enter the dungeon and find yourself in a dark room. \n");
    printf("In front of you, there are two doors, which one will you choose? (1 or 2): ");

    int door_choice;
    scanf("%d", &door_choice);

    if(door_choice == 1){
      printf("You enter the first door and find a treasure chest! Congrats, you win! \n");
    }
    else if(door_choice == 2){
      printf("You enter the second door and find a monster waiting for you. \n");
      printf("It attacks you, and you lose the game. Better luck next time! \n");
    }
    else{
      printf("Invalid choice, game over. \n");
    }

  }
  else{
    printf("You chicken out of the game, game over. \n");
  }

  return 0;
}