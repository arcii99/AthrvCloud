//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: detailed
#include<stdio.h>

int main(){
   int startLoc=0, endLoc=0, dist=0;
   
   printf("Enter Start location: ");
   scanf("%d",&startLoc);
   printf("Enter End location: ");
   scanf("%d",&endLoc);

   //Simulation of GPS navigation directions
   dist = abs(endLoc-startLoc);
   printf("Distance to destination: %d\n", dist);
   printf("Turn left after 500 meters\n");
   printf("Turn right after 1.5 kilometers\n");
   printf("Go straight for 2 kilometers\n");
   printf("Turn left after 200 meters\n");

   printf("\n\nYou have arrived!");

   return 0;
}