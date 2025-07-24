//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: Alan Touring
#include <stdio.h>

struct Location {
  float latitude;
  float longitude;
};

struct Waypoint {
  char name[50];
  struct Location location;
};

void navigate(struct Waypoint waypoints[], int num_waypoints) {
  printf("Welcome to GPS Navigation Simulation!\n");
  printf("We have %d waypoints for you to navigate through.\n", num_waypoints);

  int current_waypoint = 0;
  char choice;
  do {
    printf("\nCurrent location: %s\n", waypoints[current_waypoint].name);
    printf("What would you like to do?\n");
    printf("1. Go to next waypoint\n");
    printf("2. Go to previous waypoint\n");
    printf("3. Choose a different waypoint\n");
    printf("4. End navigation\n");
    scanf(" %c", &choice);

    switch(choice) {
      case '1':
        if (current_waypoint == num_waypoints - 1) {
          printf("You have reached the final waypoint.\n");
        } else {
          current_waypoint++;
          printf("Navigating to %s...\n", waypoints[current_waypoint].name);
        }
        break;
      case '2':
        if (current_waypoint == 0) {
          printf("You are already at the first waypoint.\n");
        } else {
          current_waypoint--;
          printf("Navigating to %s...\n", waypoints[current_waypoint].name);
        }
        break;
      case '3':
        int chosen_waypoint;
        printf("Which waypoint would you like to navigate to? (Enter a number between 1 and %d)\n", num_waypoints);
        scanf("%d", &chosen_waypoint);
        if (chosen_waypoint < 1 || chosen_waypoint > num_waypoints) {
          printf("Invalid choice.\n");
        } else {
          current_waypoint = chosen_waypoint - 1;
          printf("Navigating to %s...\n", waypoints[current_waypoint].name);
        }
        break;
      case '4':
        printf("Ending navigation.\n");
        break;
      default:
        printf("Invalid choice.\n");
    }
  } while (choice != '4');
}

int main() {
  struct Waypoint waypoints[3] = {
    {"Statue of Liberty", {40.6892, -74.0445}},
    {"Golden Gate Bridge", {37.8199, -122.4783}},
    {"Grand Canyon", {36.1069, -112.1126}}
  };

  navigate(waypoints, 3);

  return 0;
}