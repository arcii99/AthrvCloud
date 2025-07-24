//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0)); // seed random number generator
  int ghosts, goblins, spiders, bats, noises, screams; // variables for different spooky entities and sounds
  ghosts = rand() % 10 + 1; // number of ghosts between 1 and 10
  goblins = rand() % 7 + 1; // number of goblins between 1 and 7
  spiders = rand() % 25 + 1; // number of spiders between 1 and 25
  bats = rand() % 15 + 1; // number of bats between 1 and 15
  noises = rand() % 20 + 1; // number of creaking noises between 1 and 20
  screams = rand() % 5 + 1; // number of blood-curdling screams between 1 and 5
  
  printf("Welcome to the Haunted House Simulator!\n");
  printf("You are walking through a dark, creepy hallway...\n");
  printf("Suddenly, you hear strange creaking noises all around you!\n");
  
  int i;
  for (i = 1; i <= noises; i++) {
    printf("Creeeaaakkk... ");
  }
  printf("\n");
  
  printf("As you continue walking, you sense a presence nearby.\n");
  printf("You turn around, and to your horror, you see %d ghosts floating toward you!\n", ghosts);
  
  for (i = 1; i <= ghosts; i++) {
    printf("*ghostly noise*");
  }
  printf("\n");
  
  printf("You try to run away, but you're surrounded by a pack of %d goblins!\n", goblins);
  
  for (i = 1; i <= goblins; i++) {
    printf("*goblin growl*");
  }
  printf("\n");
  
  printf("You manage to shake off the goblins and run down the hall, but you run straight into a spider web!\n");
  printf("You frantically try to get the sticky web off you, but you notice %d spiders crawling all around you!\n", spiders);
  
  for (i = 1; i <= spiders; i++) {
    printf("*spider crawling noise*");
  }
  printf("\n");
  
  printf("You finally break free from the web and run even faster, but you can hear the flapping of wings getting closer...\n");
  printf("You turn around and see %d bats swooping down at you!\n", bats);
  
  for (i = 1; i <= bats; i++) {
    printf("*bat screech*");
  }
  printf("\n");
  
  printf("You're almost out of the haunted house when you hear a blood-curdling scream coming from behind you.\n");
  printf("You turn around, but it's too late. You've been caught by the notorious haunted house resident, THE BIG BAD BOOGEYMAN. \n");
  printf("%d screams echo throughout the haunted house as you join the ranks of his previous victims...\n", screams);
  
  for (i = 1; i <= screams; i++) {
    printf("*blood-curdling screams from all around*");
  }
  printf("\n");
  
  printf("GAME OVER. Better luck next time...\n");
  
  return 0;
}