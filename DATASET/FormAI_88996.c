//FormAI DATASET v1.0 Category: Educational ; Style: post-apocalyptic
#include <stdio.h>

int main() {
  int distance = 0;
  int fuel = 100;

  while (distance < 500) {
    if (fuel == 0) {
      printf("You have run out of fuel!\n");
      return 0;
    }

    printf("You are now %d miles away from safety.\n", 500 - distance);
    printf("You have %d gallons of fuel left.\n", fuel);

    int choice;
    printf("What do you want to do?\n");
    printf("1. Drive forward\n");
    printf("2. Stop and scavenge for supplies\n");
    printf("3. Rest and repair your vehicle\n");

    scanf("%d", &choice);

    switch (choice) {
      case 1:
        distance += 50;
        fuel -= 5;
        printf("You drive forward, covering 50 miles.\n");
        break;
      case 2:
        int supplies = rand() % 20 + 1;
        printf("You scavenge for supplies and find %d gallons of fuel and %d cans of food.\n", supplies, supplies);
        fuel += supplies;
        break;
      case 3:
        fuel += 10;
        printf("You rest and repair your vehicle, gaining 10 gallons of fuel.\n");
        break;
      default:
        printf("Invalid choice. Try again.\n");
    }
  }

  printf("Congratulations! You have reached safety.\n");

  return 0;
}