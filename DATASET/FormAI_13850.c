//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define MAX_BAGS 50
#define MAX_FLOORS 3

/* A struct to represent a bag */
typedef struct Bag {
  int id;
  int destination_floor;
} Bag;

/* A function to create a bag */
Bag create_bag(int id) {
  Bag bag;
  bag.id = id;
  bag.destination_floor = rand() % MAX_FLOORS + 1;
  return bag;
}

/* A function to print a bag */
void print_bag(Bag bag) {
  printf("Bag %d - Destination Floor: %d\n", bag.id, bag.destination_floor);
}

/* A function to generate bags */
int generate_bags(Bag bags[], int max_bags) {
  int i, num_bags;
  printf("Enter the number of bags to generate (max %d): ", max_bags);
  scanf("%d", &num_bags);
  for (i = 0; i < num_bags && i < max_bags; i++) {
    bags[i] = create_bag(i+1);
  }
  return i;
}

/* A struct to represent a floor */
typedef struct Floor {
  Bag bags[MAX_BAGS];
  int num_bags;
} Floor;

/* A function to print a floor */
void print_floor(Floor floor) {
  int i;
  printf("Number of bags on this floor: %d\n", floor.num_bags);
  for (i = 0; i < floor.num_bags; i++) {
    print_bag(floor.bags[i]);
  }
}

/* A function to move bags to their destination floor */
void move_bags(Floor floors[], int num_floors) {
  int i, j, num_moves = 0;
  for (i = 0; i < num_floors; i++) {
    for (j = 0; j < floors[i].num_bags; j++) {
      if (floors[i].bags[j].destination_floor != i+1) {
        // Move bag to its destination floor
        floors[floors[i].bags[j].destination_floor-1].bags[floors[floors[i].bags[j].destination_floor-1].num_bags++] = floors[i].bags[j];
        // Remove bag from current floor
        floors[i].bags[j] = floors[i].bags[--floors[i].num_bags];
        j--;
        num_moves++;
      }
    }
  }
  printf("Number of bags moved: %d\n", num_moves);
}

/* The main function */
int main() {
  srand(time(NULL)); // Seed the random number generator
  int i, num_bags, num_floors;
  Bag bags[MAX_BAGS];
  Floor floors[MAX_FLOORS];
  for (i = 0; i < MAX_FLOORS; i++) {
    floors[i].num_bags = 0;
  }
  printf("*** Airport Baggage Handling Simulation ***\n");
  printf("Enter the number of floors (max %d): ", MAX_FLOORS);
  scanf("%d", &num_floors);
  if (num_floors <= 0 || num_floors > MAX_FLOORS) {
    printf("Invalid number of floors.\n");
    return 1;
  }
  num_bags = generate_bags(bags, MAX_BAGS);
  if (num_bags == 0) {
    printf("No bags to handle.\n");
    return 0;
  }
  // Distribute bags to floors
  for (i = 0; i < num_bags; i++) {
    floors[bags[i].destination_floor-1].bags[floors[bags[i].destination_floor-1].num_bags++] = bags[i];
  }
  // Main loop
  while (true) {
    printf("*** Current State ***\n");
    for (i = 0; i < num_floors; i++) {
      printf("Floor %d:\n", i+1);
      print_floor(floors[i]);
    }
    printf("*** Move Bags? ***\n");
    printf("1. Yes\n");
    printf("2. Quit\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
      move_bags(floors, num_floors);
    } else if (choice == 2) {
      printf("Exiting...\n");
      break;
    } else {
      printf("Invalid choice.\n");
    }
  }
  return 0;
}