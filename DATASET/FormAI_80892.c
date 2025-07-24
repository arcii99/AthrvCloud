//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand((unsigned) time(NULL)); // to initialize the random number generator
  char* events[] = {"nuclear war", "alien invasion", "zombie outbreak", "climate disaster", "robot uprising", "cyber attack"};
  char* groups[] = {"Illuminati", "government", "corporations", "religious sects", "secret societies", "AI overlords"};
  char* objectives[] = {"world domination", "mind control", "immortality", "terraforming", "genetic engineering", "transcendence"};

  printf("Welcome to the Random Conspiracy Theory Generator!\n\n");

  while (1) {
    printf("Press ENTER to generate a new conspiracy theory or type Q to quit.\n");
    char input = getchar();
    if (input == 'Q' || input == 'q') {
      break;
    }
    int event_index = rand() % 6;
    int group_index = rand() % 6;
    int objective_index = rand() % 6;

    printf("\nHere's your conspiracy theory:\n\n");
    printf("After the %s caused by %s, the %s is secretly working towards their goal of %s.\n\n", events[event_index], groups[group_index], groups[group_index], objectives[objective_index]);
  }

  printf("Thank you for using the Random Conspiracy Theory Generator!\n");
  return 0;
}