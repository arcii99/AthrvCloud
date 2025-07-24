//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
   printf("Welcome to the Remote Control Car Simulation\n");

   //set up random speed and direction 
   srand(time(NULL));
   int speed = rand() % 21; //choose speed between 0 and 20
   int direction = rand() % 361; //choose direction between 0 and 360
   printf("Speed: %d mph\nDirection: %d degrees\n", speed, direction);

   //simulate a 1 hour car ride
   for(int i=1; i<=60; i++) {
      printf("Minute %d: Car is at speed %d mph, heading %d degrees\n", i, speed, direction);
      //update direction every 10 minutes
      if(i%10 == 0) {
         direction = rand() % 361;
         printf("New direction: %d degrees\n", direction);
      }
      //update speed every 5 minutes
      if(i%5 == 0) {
         int change = rand() % 11 - 5; //choose random speed change between -5 and 5 mph
         speed += change;
         if(speed < 0) {
            speed = 0;
         }
         printf("New speed: %d mph\n", speed);
      }
   }
   printf("Simulation complete! Car traveled 60 miles.\n");

   return 0;
}