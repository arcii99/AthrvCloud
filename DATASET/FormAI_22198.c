//FormAI DATASET v1.0 Category: Weather simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

   printf("\n==== WELCOME TO OUR WEATHER SIMULATION PROGRAM ====\n");

   srand(time(NULL)); // Seeding the rand() function with current time value

   char weather[4][10] = {"Sunny", "Cloudy", "Rainy", "Snowy"};
   int temperatureRange[4][2] = {{60, 80}, {50, 70}, {40, 60}, {0, 32}};
   
   // Generating random weather conditions and temperature
   int randomWeather = rand() % 4;
   int temperature = rand() % (temperatureRange[randomWeather][1] - temperatureRange[randomWeather][0] + 1) + temperatureRange[randomWeather][0];

   // Displaying the generated data to the user
   printf("\nToday's weather is %s", weather[randomWeather]);
   printf("\nThe temperature is %d degrees Fahrenheit", temperature);

   // Simulating change in weather conditions over a week
   int i;
   for (i = 1; i <= 7; i++){
      printf("\n\n===== DAY %d OF 7 =====\n", i);
      
      // Randomly selecting the probability of change in weather
      int changeProbability = rand() % 101;
      if (changeProbability > 70){
         
         // Selecting a new random weather condition and temperature
         randomWeather = rand() % 4;
         temperature = rand() % (temperatureRange[randomWeather][1] - temperatureRange[randomWeather][0] + 1) + temperatureRange[randomWeather][0];
         
         // Displaying the new weather conditions and temperature
         printf("\nToday's weather changed to %s", weather[randomWeather]);
         printf("\nThe temperature changed to %d degrees Fahrenheit", temperature);
      } else {
         
         // Displaying the same weather conditions and temperature as yesterday
         printf("\nToday's weather is the same as yesterday (%s)", weather[randomWeather]);
         printf("\nThe temperature is the same as yesterday (%d degrees Fahrenheit)", temperature);
      }
   }

   printf("\n\nThank you for using our weather simulation program!");

   return 0;
}