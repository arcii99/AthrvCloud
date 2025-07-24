//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the Text-Based Adventure Game!\n");
  printf("You find yourself in a dark room with two exits, one to the north and one to the east.\n");
  printf("Which way do you want to go? (n/e)\n");
  char direction = getchar();
  
  if(direction == 'n') {
    printf("You walk north and find yourself outside.\n");
    printf("As you look around, you see a giant dinosaur approaching you!\n");
    printf("What do you do? (r/h)\n");
    char action = getchar();
    
    if(action == 'r') {
      printf("You run as fast as you can, but the dinosaur catches up to you and eats you.\n");
      printf("Game over. Better luck next time!\n");
      exit(0);
    } else if(action == 'h') {
      printf("You hide behind a nearby rock and the dinosaur walks right past you.\n");
      printf("Whew, that was close! You continue on your adventure.\n");
    } else {
      printf("Invalid input. You stand there frozen and the dinosaur eats you.\n");
      printf("Game over. Better luck next time!\n");
      exit(0);
    }
    
  } else if(direction == 'e') {
    printf("You walk east and find yourself in a fancy castle.\n");
    printf("As you explore, you come across a room full of treasure!\n");
    printf("What do you do? (t/l)\n");
    char action = getchar();
    
    if(action == 't') {
      printf("You take as much treasure as you can carry and leave the castle victorious!\n");
      printf("Congratulations, you win the game!\n");
    } else if(action == 'l') {
      printf("You admire the treasure, but decide not to take any. You leave the castle feeling disappointed.\n");
      printf("Game over. Better luck next time!\n");
      exit(0);
    } else {
      printf("Invalid input. The castle owner catches you and throws you in the dungeon.\n");
      printf("Game over. Better luck next time!\n");
      exit(0);
    }
    
  } else {
    printf("Invalid input. You stand there confused and a monster appears out of nowhere and attacks you.\n");
    printf("Game over. Better luck next time!\n");
    exit(0);
  }
  
  return 0;
}