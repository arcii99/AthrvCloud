//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  
  printf("Welcome to the Haunted House Simulator!\n");
  printf("Are you ready to face your fears?\n");
  
  // initialize the random seed
  srand(time(NULL));
  
  // generate a random number between 1 and 10
  int ghost = rand() % 10 + 1;
  
  printf("You walk through the front door and hear strange noises...\n");
  printf("As you make your way through the house, you come across a door.\n");
  printf("Do you want to open it? (y/n)\n");
  
  char answer[10];
  fgets(answer, 10, stdin);
  
  if (answer[0] == 'y') {
    printf("You open the door and see a ghost!\n");
    
    if (ghost == 1) {
      printf("It's a friendly ghost! You ask it for help and it leads you to safety.\n");
    } else {
      printf("It's a scary ghost! You try to run, but it chases you down...\n");
      printf("GAME OVER\n");
      return 0;
    }
    
  } else {
    printf("You decide not to open the door and continue down the hallway.\n");
  }
  
  printf("You make your way to the next room and see a set of stairs.\n");
  printf("Do you want to go up or down? (u/d)\n");
  
  char direction[10];
  fgets(direction, 10, stdin);
  
  if (direction[0] == 'u') {
    printf("You climb the stairs and hear footsteps coming towards you...\n");
    printf("Do you want to hide or confront them? (h/c)\n");
    
    char action[10];
    fgets(action, 10, stdin);
    
    if (action[0] == 'h') {
      printf("You hide and the footsteps pass you by.\n");
    } else {
      printf("You confront the figure and realize it's just a statue.\n");
    }
    
  } else {
    printf("You descend the stairs and hear a creaking sound...\n");
    printf("Do you want to investigate or run away? (i/r)\n");
    
    char action[10];
    fgets(action, 10, stdin);
    
    if (action[0] == 'i') {
      printf("You investigate and find a hidden room!\n");
    } else {
      printf("You run away and bump into a wall...\n");
      printf("GAME OVER\n");
      return 0;
    }
  }
  
  printf("You continue exploring the house and come across a creepy doll.\n");
  printf("Do you want to take it with you or leave it alone? (t/l)\n");
  
  char answer2[10];
  fgets(answer2, 10, stdin);
  
  if (answer2[0] == 't') {
    printf("You take the doll with you and start to feel a strange presence...\n");
    
    if (ghost == 2 || ghost == 3) {
      printf("The ghost appears and takes the doll from you.\n");
    } else {
      printf("Nothing happens and you continue on your journey.\n");
    }
    
  } else {
    printf("You leave the doll alone and keep moving.\n");
  }
  
  printf("You finally make it to the end of the house and see a light.\n");
  printf("Do you want to go towards the light or stay in the house? (g/s)\n");
  
  char answer3[10];
  fgets(answer3, 10, stdin);
  
  if (answer3[0] == 'g') {
    printf("You walk towards the light and see the exit!\n");
    printf("Congratulations, you made it out of the haunted house!\n");
  } else {
    printf("You stay in the house and hear a voice whispering...\n");
    printf("GAME OVER\n");
    return 0;
  }
  
  return 0;
}