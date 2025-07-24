//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to hold latitude and longitude
typedef struct {
   float latitude;
   float longitude;
} LatLng;

void navigateTo(LatLng dest) {
   printf("Navigating to (%.3f, %.3f)...\n", dest.latitude, dest.longitude);

   srand(time(NULL));
   float distance = rand() % 1000 + 100;
   float time = distance / (rand() % 50 + 40);

   printf("Estimated time of arrival: %.1f minutes\n", time);
   
   char turn[20];
   int choice = rand() % 4;
   
   switch (choice) {
      case 0:
         sprintf(turn, "Turn left");
         break;
      case 1:
         sprintf(turn, "Turn right");
         break;
      case 2:
         sprintf(turn, "Make a U-turn");
         break;
      default:
         sprintf(turn, "Continue straight");
         break;
   }

   printf("%s in %d meters\n", turn, rand() % 400 + 100);
}

int main() {
   LatLng destinations[] = {
      {51.5074, -0.1278},
      {40.7128, -74.0060},
      {-33.8599, 151.2093},
      {35.6895, 139.6917}
   };
   
   printf("Welcome to GPS Navigation Sim!\n");
   printf("Press any key to start navigation.\n");

   getchar();

   int numDestinations = sizeof(destinations) / sizeof(destinations[0]);
   for (int i = 0; i < numDestinations; ++i) {
      navigateTo(destinations[i]);
   }

   printf("You have reached your final destination!\n");
   printf("Press any key to exit.\n");

   getchar();
   return 0;
}