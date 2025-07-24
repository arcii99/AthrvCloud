//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

// Function prototypes
int updateFuel(int fuel, int usage);
int rollDice(int sides);
void printStatus(int fuel, int distance, int oxygen);
void printEvent(char* event);

int main() {
  // Initialize variables
  int fuel = 100;
  int distance = 0;
  int oxygen = 10;

  // Seed random number generator
  srand(time(0));

  // Print initial status
  printStatus(fuel, distance, oxygen);

  // Main game loop
  while(distance < 1000 && oxygen > 0) {
    // Roll dice to determine event
    int roll = rollDice(6);

    // Switch case for event handling
    switch(roll) {
      case 1:
        printEvent("You encounter a black hole!");
        fuel = updateFuel(fuel, 20);
        distance = distance + 50;
        break;
      case 2:
        printEvent("You discover a new planet!");
        fuel = updateFuel(fuel, 10);
        distance = distance + 100;
        break;
      case 3:
        printEvent("Your communication system breaks down!");
        fuel = updateFuel(fuel, 5);
        oxygen = oxygen - 2;
        break;
      case 4:
        printEvent("You encounter hostile aliens!");
        fuel = updateFuel(fuel, 30);
        oxygen = oxygen - 3;
        break;
      case 5:
        printEvent("A meteor shower damages your ship!");
        fuel = updateFuel(fuel, 15);
        oxygen = oxygen - 1;
        break;
      case 6:
        printEvent("You find a wormhole!");
        fuel = updateFuel(fuel, 25);
        distance = distance + 200;
        break;
    }

    // Print updated status
    printStatus(fuel, distance, oxygen);

    // Delay for dramatic effect
    printf("...\n");
    sleep(2);
  }

  // Check if player won or lost
  if(distance >= 1000) {
    printf("Congratulations! You made it to the end of the galaxy!\n");
  } else {
    printf("Game over! You ran out of oxygen.\n");
  }

  return 0;
}

// Function to update fuel level
int updateFuel(int fuel, int usage) {
  fuel = fuel - usage;

  if(fuel < 0) {
    fuel = 0;
  }

  return fuel;
}

// Function to simulate dice rolling
int rollDice(int sides) {
  return rand() % sides + 1;
}

// Function to print current status
void printStatus(int fuel, int distance, int oxygen) {
  printf("Fuel: %d\n", fuel);
  printf("Distance: %d\n", distance);
  printf("Oxygen: %d\n", oxygen);
}

// Function to print event message
void printEvent(char* event) {
  printf("Event: %s\n", event);
}