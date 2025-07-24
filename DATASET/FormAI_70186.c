//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: expert-level
#include <stdio.h>

struct RCVehicle {
   char* name;
   int batteryLevel;
   int remoteSignalStrength;
   int xPos;
   int yPos;
};

// Function to move the vehicle by x and y directions
void moveVehicle(struct RCVehicle* vehicle, int x, int y) {
   vehicle->xPos += x;
   vehicle->yPos += y;
}

// Function to check the power status and signal strength of the vehicle
void checkStatus(struct RCVehicle* vehicle) {
   if(vehicle->batteryLevel < 20) {
      printf("Low Battery!!! Please charge the vehicle.\n");
   }
   if(vehicle->remoteSignalStrength < 50) {
      printf("Weak Signal!!! Please check the remote connection.\n");
   }
}

// Function to simulate the action of the RC Vehicle
void operateVehicle(struct RCVehicle* vehicle) {
   printf("Simulating the operation of %s vehicle...\n", vehicle->name);
   moveVehicle(vehicle, 10, 20);
   checkStatus(vehicle);
}

int main(void) {
   struct RCVehicle myVehicle = {"My Car", 80, 70, 0, 0};
   operateVehicle(&myVehicle);
   return 0;
}