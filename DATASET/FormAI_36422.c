//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

struct Point {
   double latitude;
   double longitude;
};

void navigate(struct Point current, struct Point destination) {
   double lat1, long1, lat2, long2, distance;
   lat1 = current.latitude * PI / 180.0;
   long1 = current.longitude * PI / 180.0;
   lat2 = destination.latitude * PI / 180.0;
   long2 = destination.longitude * PI / 180.0;
   distance = acos(sin(lat1)*sin(lat2) + cos(lat1)*cos(lat2)*cos(long2-long1)) * 6371.0;
   printf("The distance from current location to destination is %.2f kilometers.\n", distance);
}

int main() {
   struct Point current_location = { 40.712776, -74.005974 }; // New York City
   struct Point destination_location = { 48.856613, 2.352222 }; // Paris
   printf("User is currently located at latitude %.6f, longitude %.6f.\n", current_location.latitude, current_location.longitude);
   printf("Destination location is at latitude %.6f, longitude %.6f.\n", destination_location.latitude, destination_location.longitude);
   navigate(current_location, destination_location);
   return 0;
}