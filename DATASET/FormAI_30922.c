//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define MAX_DRONE_SPEED 100

struct Drone {
  int speed;
  int altitude;
  int direction;
};

void display_stats(struct Drone drone) {
  printf("\n----- Drone Status -----\n");
  printf("Speed: %d kph\n", drone.speed);
  printf("Altitude: %d m\n", drone.altitude);
  printf("Direction: %d degrees\n\n", drone.direction);
}

void change_speed(struct Drone *drone, int new_speed) {
  if (new_speed > MAX_DRONE_SPEED) {
    printf("Error: Speed cannot exceed %d kph.\n", MAX_DRONE_SPEED);
  } else {
    drone->speed = new_speed;
    printf("Speed set to %d kph.\n", new_speed);
  }
}

void change_altitude(struct Drone *drone, int new_altitude) {
  if (new_altitude < 0) {
    printf("Error: Altitude cannot be negative.\n");
  } else {
    drone->altitude = new_altitude;
    printf("Altitude set to %d m.\n", new_altitude);
  }
}

void change_direction(struct Drone *drone, int new_direction) {
  if (new_direction < 0 || new_direction > 360) {
    printf("Error: Direction must be between 0 and 360 degrees.\n");
  } else {
    drone->direction = new_direction;
    printf("Direction set to %d degrees.\n", new_direction);
  }
}

int main() {
  struct Drone drone1 = {50, 25, 180};
  display_stats(drone1);

  change_speed(&drone1, 75);
  change_altitude(&drone1, 50);
  change_direction(&drone1, 90);
  display_stats(drone1);

  change_speed(&drone1, 150);
  change_altitude(&drone1, -10);
  change_direction(&drone1, 450);
  display_stats(drone1);

  return 0;
}