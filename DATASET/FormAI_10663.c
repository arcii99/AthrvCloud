//FormAI DATASET v1.0 Category: Robot movement control ; Style: ephemeral
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846
#define MOTOR_MIN_RANGE 0
#define MOTOR_MAX_RANGE 50
#define SENSOR_MIN_RANGE 0
#define SENSOR_MAX_RANGE 100
#define DELAY_TIME 100

int main(void) {
  srand(time(NULL));
  int motor_left_speed = 0;
  int motor_right_speed = 0;
  int sensor_front_left = 15;
  int sensor_front_right = 35;
  int sensor_back_left = 10;
  int sensor_back_right = 20;

  while (1) {
    // Avoid obstacle if detected by front sensors
    if (sensor_front_left > SENSOR_MAX_RANGE / 2 || sensor_front_right > SENSOR_MAX_RANGE / 2) {
      motor_left_speed = rand() % (MOTOR_MAX_RANGE - MOTOR_MIN_RANGE + 1) + MOTOR_MIN_RANGE;
      motor_right_speed = rand() % (MOTOR_MAX_RANGE - MOTOR_MIN_RANGE + 1) + MOTOR_MIN_RANGE;
      if (sensor_front_left > sensor_front_right) {
        printf("Obstacle detected on left. Turning right.\n");
        motor_left_speed = motor_left_speed + motor_left_speed * (sensor_front_left - SENSOR_MAX_RANGE / 2) / SENSOR_MAX_RANGE;
        motor_right_speed = motor_right_speed - motor_right_speed * (sensor_front_left - SENSOR_MAX_RANGE / 2) / SENSOR_MAX_RANGE;
      } else {
        printf("Obstacle detected on right. Turning left.\n");
        motor_left_speed = motor_left_speed - motor_left_speed * (sensor_front_right - SENSOR_MAX_RANGE / 2) / SENSOR_MAX_RANGE;
        motor_right_speed = motor_right_speed + motor_right_speed * (sensor_front_right - SENSOR_MAX_RANGE / 2) / SENSOR_MAX_RANGE;
      }
    } else {
      // Move forward
      printf("Moving forward.\n");
      motor_left_speed = rand() % (MOTOR_MAX_RANGE - MOTOR_MIN_RANGE + 1) + MOTOR_MIN_RANGE;
      motor_right_speed = rand() % (MOTOR_MAX_RANGE - MOTOR_MIN_RANGE + 1) + MOTOR_MIN_RANGE;
    }
    // Update sensor readings for next iteration
    sensor_front_left = rand() % (SENSOR_MAX_RANGE - SENSOR_MIN_RANGE + 1) + SENSOR_MIN_RANGE;
    sensor_front_right = rand() % (SENSOR_MAX_RANGE - SENSOR_MIN_RANGE + 1) + SENSOR_MIN_RANGE;
    sensor_back_left = rand() % (SENSOR_MAX_RANGE - SENSOR_MIN_RANGE + 1) + SENSOR_MIN_RANGE;
    sensor_back_right = rand() % (SENSOR_MAX_RANGE - SENSOR_MIN_RANGE + 1) + SENSOR_MIN_RANGE;

    printf("Left motor speed: %d, Right motor speed: %d\n", motor_left_speed, motor_right_speed);
    printf("Front left sensor reading: %d, Front right sensor reading: %d\n", sensor_front_left, sensor_front_right);
    printf("Back left sensor reading: %d, Back right sensor reading: %d\n", sensor_back_left, sensor_back_right);
    printf("\n");

    // Delay to simulate robot movement
    usleep(DELAY_TIME * 1000);
  }
  return 0;
}