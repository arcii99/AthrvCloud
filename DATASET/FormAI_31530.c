//FormAI DATASET v1.0 Category: Weather simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int temperature;
   int windspeed;
   char weather[50];

   srand(time(NULL));

   temperature = (rand() % 20) + 15;
   windspeed = (rand() % 40) + 10;
   
   if (temperature >= 35 && windspeed >= 25) {
      strcpy(weather, "Heatwave alert!");
   } else if (temperature >= 30 && windspeed >= 20) {
      strcpy(weather, "It's really windy and hot");
   } else if (temperature >= 30 && windspeed >= 15) {
      strcpy(weather, "It's fairly hot and breezy");
   } else if (temperature >= 25 && windspeed >= 10) {
      strcpy(weather, "It's a pleasant day with a nice breeze");
   } else if (temperature >= 20 && windspeed >= 5) {
      strcpy(weather, "It's nice and sunny outside");
   } else {
      strcpy(weather, "It's a bit chilly out there");
   }
   
   printf("Today's temperature is %d degrees Celsius.\n", temperature);
   printf("Today's windspeed is %d km/hour.\n", windspeed);
   printf("Today's weather forecast: %s\n", weather);

   return 0;

}