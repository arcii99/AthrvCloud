//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main() {
  int speed = 0;
  int direction = 0;
  int is_obstacle_detected = 0;

  printf("Remote control vehicle simulation\n");

  while(1) {
    printf("Enter speed (0-10): ");
    scanf("%d", &speed);
    fflush(stdin);

    printf("Enter direction (-180 to 180): ");
    scanf("%d", &direction);
    fflush(stdin);

    printf("Obstacle detected? (0/1): ");
    scanf("%d", &is_obstacle_detected);
    fflush(stdin);

    if (is_obstacle_detected) {
      printf("Obstacle detected. Stopping vehicle.\n");
      speed = 0;
    }

    printf("Vehicle is moving with speed %d at direction %d.\n", speed, direction);

    if (speed == 0) {
      printf("Vehicle has stopped.\n");
    }
    
    printf("Do you want to continue? (y/n) ");
    char response = getchar();

    if (response != 'y') {
      break;
    }

    fflush(stdin);
    system("clear");
  }

  printf("Thank you for using the remote control vehicle simulator!\n");
  return 0;
}