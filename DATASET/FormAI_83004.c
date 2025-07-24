//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: invasive
#include <stdio.h>
#include <math.h>

#define RADIUS 6371 // Earth's radius in km

struct Location {
   double lat;
   double lng;
};

// Function to calculate the distance between two locations using Haversine formula
double getDistance(struct Location loc1, struct Location loc2) {
   double latDist = (loc2.lat - loc1.lat) * M_PI / 180.0;
   double lngDist = (loc2.lng - loc1.lng) * M_PI / 180.0;
   
   double a = sin(latDist / 2) * sin(latDist / 2) + cos(loc1.lat * M_PI / 180.0) * cos(loc2.lat * M_PI / 180.0) * sin(lngDist / 2) * sin(lngDist / 2);
   double c = 2 * atan2(sqrt(a), sqrt(1 - a));
   
   return RADIUS * c;
}

int main() {
   // Define current and destination locations
   struct Location currentLoc = { 51.5074, 0.1278 }; // London coordinates
   struct Location destLoc = { 40.7128, -74.0060 }; // New York coordinates
 
   // Display current location
   printf("Current Location: (%lf, %lf)\n", currentLoc.lat, currentLoc.lng);

   // Display distance to destination
   double distance = getDistance(currentLoc, destLoc);
   printf("Distance to Destination: %lf km\n", distance);
 
   // Calculate bearing angle to destination
   double lat1 = currentLoc.lat * M_PI / 180.0;
   double lat2 = destLoc.lat * M_PI / 180.0;
   double lngDiff = (destLoc.lng - currentLoc.lng) * M_PI / 180.0;

   double y = sin(lngDiff) * cos(lat2);
   double x = cos(lat1) * sin(lat2) - sin(lat1) * cos(lat2) * cos(lngDiff);
   double bearing = atan2(y, x) * 180 / M_PI;
   
   if (bearing < 0) {
      bearing += 360;
   }

   // Display bearing angle to destination
   printf("Bearing to Destination: %lf degrees\n", bearing);
 
   return 0;
}