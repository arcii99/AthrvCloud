//FormAI DATASET v1.0 Category: Weather simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int location;
   int temperature[12] = {24, 23, 22, 20, 18, 16, 17, 19, 20, 21, 22, 23};
   int precipitation[12] = {10, 15, 20, 40, 60, 70, 80, 90, 80, 60, 30, 20};
   char* location_name[5] = {"London", "Paris", "Sydney", "New York", "Tokyo"};
   
   // Get random location
   srand(time(NULL));
   location = rand() % 5;
   
   // Print current location and weather conditions
   printf("Location: %s\n", location_name[location]);
   printf("Temperature: %dC\n", temperature[location]);
   printf("Precipitation: %d%%\n", precipitation[location]);
   
   // Determine if it's raining/snowing and output appropriate message
   if (precipitation[location] > 50) {
      if (temperature[location] < 0) {
         printf("It's currently snowing\n");
      } else {
         printf("It's currently raining\n");
      }
   } else {
      printf("It's currently dry\n");
   }
   
   // Determine if it's hot/cold and output appropriate message
   if (temperature[location] > 25) {
      printf("It's currently hot outside\n");
   } else if (temperature[location] < 10) {
      printf("It's currently very cold outside\n");
   } else {
      printf("It's currently a comfortable temperature\n");
   }
   
   // Determine if it's spring/summer/fall/winter and output appropriate message
   switch(location) {
      case 0:
      case 1:
         printf("It's currently fall in the northern hemisphere\n");
         break;
      case 2:
         printf("It's currently spring in the southern hemisphere\n");
         break;
      case 3:
         printf("It's currently winter in the northern hemisphere\n");
         break;
      case 4:
         printf("It's currently summer in the northern hemisphere\n");
         break;
      default:
         printf("Unknown location\n");
   }
   
   return 0;
}