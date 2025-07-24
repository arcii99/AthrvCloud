//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: multivariable
#include <stdio.h>

struct vehicle {
   int speed;
   int direction;
   int battery;
   char mode[10];
};

int main() {
   struct vehicle car;
   
   printf("Enter speed: ");
   scanf("%d", &car.speed);
   
   printf("Enter direction (in degrees): ");
   scanf("%d", &car.direction);
   
   printf("Enter battery percentage: ");
   scanf("%d", &car.battery);
   
   printf("Enter mode (Manual, Autonomous): ");
   scanf("%s", car.mode);
   
   printf("\nYour remote control vehicle simulation: \n");
   printf("Speed: %d mph\n", car.speed);
   printf("Direction: %d°\n", car.direction);
   printf("Battery: %d%%\n", car.battery);
   printf("Mode: %s\n", car.mode);
   
   return 0;
}