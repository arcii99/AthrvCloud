//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));

  // Generate random obstacles for the track
  int obstacles[10];
  for (int i = 0; i < 10; i++) {
    obstacles[i] = rand() % 100 + 1;
  }

  printf("Welcome to the Remote Control Vehicle Simulation!\n");
  printf("Avoid the obstacles and reach the finish line to win.\n");

  int distance = 0;
  int speed = 0;
  int health = 100;

  // Begin race loop
  while (distance < 1000) {
    
    printf("----------------------------------------------\n");
    
    printf("Distance Travelled: %d meters\n", distance);
    printf("Vehicle Speed: %d km/h\n", speed);
    printf("Vehicle Health: %d%%\n", health);
    
    // Randomly generate if there's an obstacle ahead
    int obstacle_index = -1;
    if (rand() % 2 == 0) {
      obstacle_index = rand() % 10;
    }
    
    if (obstacle_index != -1 && obstacles[obstacle_index] <= distance) {
      printf("OBSTACLE AHEAD! Swerve to avoid.\n");
      health -= 10;

      // Randomly generate if the vehicle successfully avoids obstacle
      if (rand() % 2 == 0) {
        printf("You successfully avoided the obstacle!\n");
      } else {
        printf("CRASH! Your vehicle is damaged.\n");
        speed /= 2;
        health -= 30;
      }
    }
    
    if (health <= 0) {
      printf("VEHICLE DESTROYED. GAME OVER.\n");
      break;
    }

    distance += speed;
    speed += rand() % 30 + 1;

    if (speed > 120) {
      printf("VEHICLE OVERHEATING. SLOW DOWN.\n");
      health -= 5;
      speed = 100;
    }

    if (distance >= 1000) {
      printf("Congratulations! You reached the finish line.\n");
    }

    // Delay for dramatic effect
    for (int i = 0; i < 50000000; i++) {}
  }

  return 0;
}