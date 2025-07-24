//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: safe
#include <stdio.h>

int main() {

   double lat, longi, destLat, destLong;
   double xDistance, yDistance, distance;
   char direction[10] = "";

   printf("Enter your current latitude: ");
   scanf("%lf", &lat);

   printf("Enter your current longitude: ");
   scanf("%lf", &longi);

   printf("Enter the latitude of your destination: ");
   scanf("%lf", &destLat);

   printf("Enter the longitude of your destination: ");
   scanf("%lf", &destLong);

   // Calculate x and y distance between current location and destination
   xDistance = (destLong - longi) * cos((lat + destLat) / 2);
   yDistance = destLat - lat;

   // Calculate the total distance between current location and destination
   distance = sqrt(pow(xDistance, 2) + pow(yDistance, 2)) * 6371;

   // Determine direction of the destination based on x and y distance
   if (xDistance > 0) {
      strcpy(direction, "East");
   } else if (xDistance < 0) {
      strcpy(direction, "West");
   }
   if (yDistance > 0) {
      strcat(direction, "North");
   } else if (yDistance < 0) {
      strcat(direction, "South");
   }

   printf("\nDistance to destination: %.2lf km", distance);
   printf("\nDirection to destination: %s\n", direction);

   return 0;
}