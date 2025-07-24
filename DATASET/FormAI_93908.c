//FormAI DATASET v1.0 Category: Robot movement control ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// declare global variables
int x_position, y_position, x_destination, y_destination;

// function to generate random coordinates from 0 to 100
void generateCoordinates() {
  srand(time(NULL)); // seed for random number generator
  x_position = rand() % 101;
  y_position = rand() % 101;
  x_destination = rand() % 101;
  y_destination = rand() % 101;
}

int main() {
  generateCoordinates(); // generate random starting and destination coordinates
  
  // initialize movement variables
  int x_difference = x_destination - x_position;
  int y_difference = y_destination - y_position;
  
  printf("Current position: (%d, %d)\n", x_position, y_position);
  printf("Destination: (%d, %d)\n", x_destination, y_destination);
  
  if (x_difference > 0) {
    printf("Moving right\n");
    while (x_position < x_destination) {
      x_position++;
      printf("(%d, %d)\n", x_position, y_position);
    }
  } else {
    printf("Moving left\n");
    while (x_position > x_destination) {
      x_position--;
      printf("(%d, %d)\n", x_position, y_position);
    }
  }
  
  if (y_difference > 0) {
    printf("Moving up\n");
    while (y_position < y_destination) {
      y_position++;
      printf("(%d, %d)\n", x_position, y_position);
    }
  } else {
    printf("Moving down\n");
    while (y_position > y_destination) {
      y_position--;
      printf("(%d, %d)\n", x_position, y_position);
    }
  }
  
  printf("Reached destination at (%d, %d)\n", x_destination, y_destination);
  
  return 0;
}