//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: standalone
#include <stdio.h>

struct remote_control_vehicle {
  char* model;
  int battery_level;
  int speed;
  int distance_travelled;
};

void display_vehicle_info(struct remote_control_vehicle* vehicle) {
  printf("Model: %s\n", vehicle->model);
  printf("Battery Level: %d%%\n", vehicle->battery_level);
  printf("Speed: %d km/h\n", vehicle->speed);
  printf("Distance Travelled: %d km\n", vehicle->distance_travelled);
  printf("-------------------------\n");
}

int main() {
  struct remote_control_vehicle vehicle1 = {"Monster Truck", 100, 0, 0};
  struct remote_control_vehicle vehicle2 = {"Formula One", 75, 0, 0};
  
  printf("Initial Vehicle Info:\n");
  display_vehicle_info(&vehicle1);
  display_vehicle_info(&vehicle2);
  
  // simulate vehicles moving
  vehicle1.speed = 20;
  vehicle1.distance_travelled = 50;
  vehicle2.speed = 30;
  vehicle2.distance_travelled = 75;
  
  printf("Modified Vehicle Info:\n");
  display_vehicle_info(&vehicle1);
  display_vehicle_info(&vehicle2);
  
  return 0; 
}