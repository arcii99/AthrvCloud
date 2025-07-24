//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// Define struct for drone remote control
struct DroneRemoteControl {
  int battery_level;
  int altitude;
  int direction;
  int speed;
  int frequency;
};

// Function to initialize drone remote control
void initialize_drone_control(struct DroneRemoteControl *drone) {
  drone->battery_level = 100;
  drone->altitude = 0;
  drone->direction = 0;
  drone->speed = 0;
  drone->frequency = 2.4;
}

// Function to print drone remote control status
void print_drone_status(struct DroneRemoteControl drone) {
  printf("Battery level: %d%%\n", drone.battery_level);
  printf("Altitude: %d meters\n", drone.altitude);
  printf("Direction: %d degrees\n", drone.direction);
  printf("Speed: %d km/h\n", drone.speed);
  printf("Frequency: %d GHz\n", drone.frequency);
}

// Function to change drone direction
void change_direction(struct DroneRemoteControl *drone, int degree) {
  drone->direction = degree;
}

// Function to change drone speed
void change_speed(struct DroneRemoteControl *drone, int kmh) {
  drone->speed = kmh;
}

// Function to take off drone
void take_off(struct DroneRemoteControl *drone) {
  if (drone->altitude == 0) {
    printf("Taking off...\n");
    drone->altitude = 3;
  } else {
    printf("Drone is already in the air!\n");
  }
}

// Function to land drone
void land(struct DroneRemoteControl *drone) {
  if (drone->altitude == 0) {
    printf("Drone is already on the ground!\n");
  } else {
    printf("Landing...\n");
    drone->altitude = 0;
  }
}

// Main function
int main() {
  // Initialize drone remote control
  struct DroneRemoteControl drone;
  initialize_drone_control(&drone);

  // Print drone status
  printf("Initial drone status:\n");
  print_drone_status(drone);

  // Change drone direction and speed
  change_direction(&drone, 90);
  change_speed(&drone, 30);

  // Print drone status again
  printf("New drone status:\n");
  print_drone_status(drone);

  // Take off drone
  take_off(&drone);

  // Print drone status again
  printf("Drone is in the air!\n");
  print_drone_status(drone);

  // Land drone
  land(&drone);

  // Print drone status again
  printf("Drone has landed!\n");
  print_drone_status(drone);

  // Return 0 to indicate successful execution
  return 0;
}