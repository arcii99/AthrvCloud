//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the Drone Remote Control System\n");
  printf("Please enter the flight mode: ");
  char flight_mode[10];
  scanf("%s", flight_mode);

  if (strcmp(flight_mode, "manual") == 0) {
    printf("Entering manual flight mode...\n");
    printf("Use the arrow keys to control the drone\n");
    printf("Press 'q' to quit the program\n");
    char key_pressed;

    do {
      key_pressed = getchar();
      if (key_pressed == 27) { // arrow key detected
        key_pressed = getchar(); // skip the [
        key_pressed = getchar();
        if (key_pressed == 65) { // up arrow key
          printf("Drone moving forward...\n");
        } else if (key_pressed == 66) { // down arrow key
          printf("Drone moving backward...\n");
        } else if (key_pressed == 67) { // right arrow key
          printf("Drone moving right...\n");
        } else if (key_pressed == 68) { // left arrow key
          printf("Drone moving left...\n");
        }
      } else if (key_pressed == 'q') {
        printf("Quitting the program...\n");
        exit(0);
      }
    } while (1);
  } else if (strcmp(flight_mode, "autonomous") == 0) {
    printf("Entering autonomous flight mode...\n");
    printf("Starting the drone's artificial intelligence system...\n");
    printf("Program halted due to machine learning taking over the drones controlled missions...\n");
  } else {
    printf("Invalid flight mode entered.\nPlease try again.\n");
  }

  return 0;
}