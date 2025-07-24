//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: romantic
#include <stdio.h>
#include <math.h>

int main() {
   double latitude, longitude, destination_latitude, destination_longitude, distance;

   printf("Enter your current latitude: ");
   scanf("%lf", &latitude);

   printf("Enter your current longitude: ");
   scanf("%lf", &longitude);

   printf("Enter your beloved's latitude: ");
   scanf("%lf", &destination_latitude);

   printf("Enter your beloved's longitude: ");
   scanf("%lf", &destination_longitude);

   distance = acos(sin(latitude)*sin(destination_latitude) + cos(latitude)*cos(destination_latitude)*cos(destination_longitude-longitude)) * 6371;

   printf("You are %.2f miles away from your beloved.\n\n", distance);

   while (distance > 0.1) {
       if (distance > 20) {
           printf("Turn left and take her/his hand.\n");
       } else if (distance > 5) {
           printf("Drive straight and hold your lover's hand.\n");
       } else {
           printf("Turn right and tell her/him how much you love.\n");
       }

       latitude = destination_latitude;
       longitude = destination_longitude;

       printf("Enter your beloved's latitude: ");
       scanf("%lf", &destination_latitude);

       printf("Enter your beloved's longitude: ");
       scanf("%lf", &destination_longitude);

       distance = acos(sin(latitude)*sin(destination_latitude) + cos(latitude)*cos(destination_latitude)*cos(destination_longitude-longitude)) * 6371;

       printf("You are %.2f miles away from your beloved.\n\n", distance);
   }

   printf("You have arrived at your destination. Enjoy your time with your beloved.\n");

   return 0;
}