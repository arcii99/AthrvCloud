//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

typedef struct {
   float latitude;
   float longitude;
} Location;

Location getLocation(){
   Location location;
   printf("Enter Latitude: ");
   scanf("%f", &location.latitude);
   printf("Enter Longitude: ");
   scanf("%f", &location.longitude);
   return location;
}

void printLocation(Location location){
   printf("%f, %f\n", location.latitude, location.longitude);
}

float calculateDistance(Location location1, Location location2){
   float distance = 0;
   distance = sqrt(pow(location1.latitude - location2.latitude, 2) + pow(location1.longitude - location2.longitude, 2));
   return distance;
}

void navigateToDestination(){
   Location sourceLocation, destinationLocation;
   printf("Enter Source Location:\n");
   sourceLocation = getLocation();
   printf("Enter Destination Location:\n");
   destinationLocation = getLocation();
   printf("Source Location: ");
   printLocation(sourceLocation);
   printf("Destination Location: ");
   printLocation(destinationLocation);
   printf("Distance to destination: %f\n", calculateDistance(sourceLocation, destinationLocation));
}

int main(){
   printf("GPS Navigation Simulation\n");
   navigateToDestination();
   return 0;
}