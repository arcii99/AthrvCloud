//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  printf("Welcome to the Space Adventure Game!\n");

  printf("Please enter your name: ");
  char name[20];
  scanf("%s", &name);
  printf("Hello %s!\n", name);

  printf("You are about to embark on a mission to explore a distant planet.\n");
  printf("Your spaceship will be your home for the next 6 months.\n");
  printf("Are you ready to begin? (Enter y/n): ");

  char start;
  scanf("%s", &start);

  if (start == 'n') {
    printf("Goodbye!\n");
    return 0; 
  }

  int distance = 10000;
  int fuel = 100;
  int alien_attack = 0;
  srand(time(NULL));
  int alien_chance = rand() % 101;

  while (distance > 0 && fuel > 0) {
    printf("You are %d miles away from the planet and have %d units of fuel.\n", distance, fuel);
    printf("What would you like to do? (Enter a number)\n");
    printf("1. Move closer to the planet\n");
    printf("2. Refuel your ship\n");
    printf("3. Attempt to communicate with any alien lifeforms\n");
    printf("4. Wait and see what happens (this could be good or bad)\n");

    int choice;
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        distance -= 1000;
        fuel -= 20;
        alien_attack = 0;
        break;
      case 2:
        fuel += 50;
        break;
      case 3:
        if (alien_chance > 50) {
          printf("You have made contact with a friendly alien race!\n");
          printf("They have given you advanced technology to improve your mission.\n");
          distance -= 500;
          fuel -= 10;
        } else {
          printf("You have encountered hostile aliens! They have damaged your ship!\n");
          alien_attack = 1;
          fuel -= 25;
        }
        break;
      case 4:
        int good_or_bad = rand() % 2;
        if (good_or_bad == 0) {
          printf("Nothing exciting happens.\n");
          fuel -= 5;
        } else {
          printf("You discover a rich source of fuel on an asteroid nearby!\n");
          fuel += 25;
        }
        break;
      default:
        printf("Invalid choice. Please try again.\n");
        break;
    }

    if (alien_attack == 1) {
      printf("Your ship has sustained damage from the alien attack. You must repair it before continuing.\n");
      printf("Repair the ship? (Enter y/n): ");
      char repair;
      scanf("%s", &repair);
      if (repair == 'y') {
        fuel -= 10;
        alien_attack = 0;
        printf("Your ship has been fully repaired.\n");
      } else {
        printf("Your ship remains damaged and cannot continue until it is repaired.\n");
        break;
      }
    }
  }

  if (distance <= 0 && fuel >= 0) {
    printf("Congratulations! You have successfully landed on the planet and completed your mission!\n");
  } else {
    printf("Mission failed. Your ship has run out of fuel or been destroyed by aliens.\n");
  }
  
  return 0;
}