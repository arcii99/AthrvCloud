//FormAI DATASET v1.0 Category: Robot movement control ; Style: surprised
#include <stdio.h>

int main() {
  printf("I am so surprised! I can control robot movement now!\n");

  int speed = 0;
  int direction = 0;

  printf("Enter speed and direction in the format: speed, direction (ex. 50, 90): ");
  scanf("%d, %d", &speed, &direction);

  while(speed > 0 && direction > 0) {
    // Move robot forward
    printf("Moving robot forward with speed of %d and direction of %d degrees\n", speed, direction);

    // Read new speed and direction from user
    printf("Enter new speed and direction in the format: speed, direction (ex. 25, 180): ");
    scanf("%d, %d", &speed, &direction);
  }

  printf("Robot has stopped moving. Thank you for using this program!\n");

  return 0;
}