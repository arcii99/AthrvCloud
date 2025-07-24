//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // init random seed
  int x = 0, y = 0, speed = 0, direction = 0;
  
  printf("Welcome to the Remote Control Vehicle Simulation!\n");

  while (1) {
    printf("\nCurrent position: (%d, %d)\n", x, y);
    printf("Enter speed (1-10): ");
    scanf("%d", &speed);

    if (speed <= 0 || speed > 10) {
      printf("Invalid input, please enter a speed between 1 and 10.\n");
      continue;
    }

    printf("Enter direction (0-360): ");
    scanf("%d", &direction);

    if (direction < 0 || direction >= 360) {
      printf("Invalid input, please enter a direction between 0 and 360.\n");
      continue;
    }

    // calculate new position
    int distance = speed * (rand() % 10 + 1);
    float radians = (float) direction * 3.14159 / 180.0;
    int dx = (int) (distance * cos(radians) + 0.5);
    int dy = (int) (distance * sin(radians) + 0.5);
    x += dx;
    y += dy;

    printf("Moving %d units in direction %d...\n", distance, direction);
    printf("New position: (%d, %d)\n", x, y);
  }

  return 0;
}