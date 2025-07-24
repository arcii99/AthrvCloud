//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: systematic
#include <stdio.h>

//Defining our Remote Control Vehicle struct
struct RemoteControlVehicle {
   int speed;
   int direction;
};

int main() {
   //Intializing our struct with default values
   struct RemoteControlVehicle rc_vehicle = {0, 0};

   //Printing the initial state of our RC vehicle
   printf("Initial State: \nSpeed: %d \nDirection: %d\n\n", rc_vehicle.speed, rc_vehicle.direction);

   //Getting user input for speed and direction of the RC vehicle
   printf("Enter speed (1-10): ");
   scanf("%d", &rc_vehicle.speed);

   printf("Enter direction (0-360): ");
   scanf("%d", &rc_vehicle.direction);

   //Printing the updated state of our RC vehicle
   printf("\nUpdated State: \nSpeed: %d \nDirection: %d\n\n", rc_vehicle.speed, rc_vehicle.direction);

   //Simulating movement of RC vehicle
   printf("Moving RC vehicle...\n");
   for(int i=0; i<10; i++) {
      printf("Speed: %d, Direction: %d\n", rc_vehicle.speed, rc_vehicle.direction);
   }

   //Returning success code
   return 0;
}