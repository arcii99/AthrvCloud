//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char choice;
  srand(time(NULL)); // initialize random seed
  printf("Welcome to the Haunted House Simulator!\n");
  printf("You have entered a haunted house. Do you want to explore? (y/n)\n");
  scanf("%c", &choice);

  while(choice == 'y') {
    int dir = rand() % 4; // choose random direction
    switch(dir) {
      case 0:
        printf("You hear a strange noise from the east.\n");
        break;
      case 1:
        printf("You feel a cold breeze from the north.\n");
        break;
      case 2:
        printf("You smell a foul odor from the west.\n");
        break;
      case 3:
        printf("You see a shadow move from the south.\n");
        break;
    }

    printf("Do you want to continue exploring? (y/n)\n");
    scanf(" %c", &choice);
  }

  printf("Thanks for playing!\n");
  return 0;
}