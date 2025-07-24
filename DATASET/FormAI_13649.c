//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_DESC_LENGTH 50

struct Location {
  char name[MAX_NAME_LENGTH];
  char description[MAX_DESC_LENGTH];
  int north, east, south, west;
};

void print_location(struct Location* location) {
  printf("\n---------------------------\n");
  printf("%s\n", location->name);
  printf("%s\n\n", location->description);
  printf("North: %d\n", location->north);
  printf("East: %d\n", location->east);
  printf("South: %d\n", location->south);
  printf("West: %d\n", location->west);
  printf("---------------------------\n\n");
}

int main() {
  struct Location locations[5] = {
    {"Room 1", "A small, dimly lit room.", -1, 1, -1, -1},
    {"Room 2", "A large, spacious room.", -1, 2, -1, 0},
    {"Room 3", "A dark and creepy room.", 1, -1, 4, -1},
    {"Room 4", "A room filled with treasure!", 3, 4, -1, -1},
    {"Room 5", "A long, dusty hallway.", -1, 3, -1, 1}
  };

  int current_location = 0;
  char input[10];

  printf("Welcome to the Adventure Game!\n\n");

  while (1) {
    print_location(&locations[current_location]);

    printf("Enter direction or 'quit': ");
    fgets(input, 10, stdin);

    if (strcmp(input, "quit\n") == 0) {
      printf("Thanks for playing!\n");
      exit(0);
    } else if (strcmp(input, "north\n") == 0) {
      if (locations[current_location].north != -1) {
        current_location = locations[current_location].north;
      } else {
        printf("You can't go that way.\n");
      }
    } else if (strcmp(input, "east\n") == 0) {
      if (locations[current_location].east != -1) {
        current_location = locations[current_location].east;
      } else {
        printf("You can't go that way.\n");
      }
    } else if (strcmp(input, "south\n") == 0) {
      if (locations[current_location].south != -1) {
        current_location = locations[current_location].south;
      } else {
        printf("You can't go that way.\n");
      }
    } else if (strcmp(input, "west\n") == 0) {
      if (locations[current_location].west != -1) {
        current_location = locations[current_location].west;
      } else {
        printf("You can't go that way.\n");
      }
    } else {
      printf("Invalid input.\n");
    }
  }

  return 0;
}