//FormAI DATASET v1.0 Category: Smart home automation ; Style: real-life
#include <stdio.h>

int main() {
   int roomTemp = 23; // initialize the room temperature
   int desiredTemp = 20; // initialize the desired temperature

   printf("Welcome to Smart Home Automation System!\n");
   printf("The current temperature of the room is %d degrees Celsius.\n", roomTemp);

   // check if the desired temperature is not equal to the room temperature
   while (desiredTemp != roomTemp) {
      if (desiredTemp < roomTemp) {
         printf("Lowering room temperature by 1 degree Celsius.\n");
         roomTemp--;
      } else {
         printf("Increasing room temperature by 1 degree Celsius.\n");
         roomTemp++;
      }
      printf("The current temperature of the room is now %d degrees Celsius.\n", roomTemp);
   }
   
   // turn on lights if it's dark outside
   int isDark = 1; // initialize the darkness state
   if (isDark) {
      printf("It's dark outside. Turning on lights.\n");
   } else {
      printf("It's bright outside. Lights are off.\n");
   }

   // turn on the TV if anyone is in the living room
   int isLivingRoomOccupied = 1; // initialize the living room occupancy state
   if (isLivingRoomOccupied) {
      printf("Someone is in the living room. Turning on the TV.\n");
   } else {
      printf("No one is in the living room. TV is off.\n");
   }

   // lock the front door if no one is home
   int isAnyoneHome = 0; // initialize the home occupancy state
   if (!isAnyoneHome) {
      printf("No one is home. Locking the front door.\n");
   }

   printf("Smart Home Automation System program completed successfully.\n");
   return 0;
}