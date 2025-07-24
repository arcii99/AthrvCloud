//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: light-weight
#include <stdio.h>

// Remote control vehicle simulation function
void rc_vehicle_simulator(int speed, int direction, int battery_life) {
  printf("Speed: %d mph\n", speed);
  printf("Direction: %d degrees\n", direction);
  
  if (battery_life == 100) {
    printf("Battery life: Fully charged\n");
  } else if (battery_life < 100 && battery_life >= 50) {
    printf("Battery life: %d%%\n", battery_life);
  } else if (battery_life < 50 && battery_life >= 20) {
    printf("Battery life: %d%% - Low battery warning\n", battery_life);
  } else {
    printf("Battery life: %d%% - Critical battery warning\n", battery_life);
  }
  
  printf("\n");
}

int main() {
  // Example usage of the remote control vehicle simulation function
  printf("Initializing remote control vehicle simulator...\n\n");
  
  int battery_life = 100;
  
  printf("Starting vehicle...\n");
  rc_vehicle_simulator(10, 20, battery_life);
  
  printf("Turning left...\n");
  rc_vehicle_simulator(10, 0, battery_life);
  
  printf("Increasing speed...\n");
  rc_vehicle_simulator(20, 0, battery_life);
  
  printf("Decreasing speed...\n");
  rc_vehicle_simulator(10, 0, battery_life);
  
  printf("Turning right...\n");
  rc_vehicle_simulator(10, 60, battery_life);
  
  printf("Decreasing battery life...\n");
  battery_life = 75;
  rc_vehicle_simulator(5, 0, battery_life);
  
  printf("Critical battery warning...\n");
  battery_life = 5;
  rc_vehicle_simulator(0, 0, battery_life);
  
  return 0;
}