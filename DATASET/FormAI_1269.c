//FormAI DATASET v1.0 Category: Weather simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int weather[7][24]; // 7 days and 24 hours
   int max_temp = 35, min_temp = 10, max_humidity = 100, min_humidity = 10;
   srand(time(NULL)); // seed for random numbers
   
   // generate weather data for each day and hour
   for(int i=0; i<7; i++) {
      for(int j=0; j<24; j++) {
         weather[i][j] = rand() % (max_temp - min_temp + 1) + min_temp; // generate temperature
         int humidity = rand() % (max_humidity - min_humidity + 1) + min_humidity; // generate humidity
         if(weather[i][j] > 30 && humidity > 80) { // check for rain
            printf("It's raining at %d:00 hours on day %d\n", j, i+1);
         }
         else { // print temperature and humidity data
            printf("Temperature on day %d at %02d:00 hours is %d C\n", i+1, j, weather[i][j]);
            printf("Humidity on day %d at %02d:00 hours is %d%%\n", i+1, j, humidity);
         }
      }
   }
   
   return 0;
}