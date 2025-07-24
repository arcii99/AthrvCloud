//FormAI DATASET v1.0 Category: Weather simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   // Initializing random number generator
   srand(time(0));
   
   // Setting the minimum and maximum temperature range
   int min_temp = 60, max_temp = 90;
   
   // Generating a random temperature
   int temperature = (rand() % (max_temp - min_temp + 1)) + min_temp;
   
   // Setting the minimum and maximum humidity range
   int min_humidity = 20, max_humidity = 80;
   
   // Generating a random humidity level
   int humidity = (rand() % (max_humidity - min_humidity + 1)) + min_humidity;
   
   // Setting the minimum and maximum rain range
   int min_rain = 0, max_rain = 5;
   
   // Generating a random amount of rain
   int rain = (rand() % (max_rain - min_rain + 1)) + min_rain;
   
   // Outputting the weather conditions
   printf("Today's weather conditions:\n");
   printf("Temperature: %d degrees Fahrenheit\n", temperature);
   printf("Humidity: %d%%\n", humidity);
   printf("Rain: %d inches\n", rain);
   
   // Assessing the weather conditions
   if(temperature >= 80 && humidity >= 70 && rain == 0) {
      printf("It's a hot and humid day - make sure to stay hydrated!\n");
   } else if(temperature <= 70 && humidity <= 30 && rain == 0) {
      printf("It's a cool and dry day - perfect for outdoor activities!\n");
   } else if(temperature >= 80 && humidity >= 70 && rain > 0) {
      printf("It's a humid day with some rain - stay indoors if possible.\n");
   } else if(temperature <= 70 && humidity <= 30 && rain > 0) {
      printf("It's a cool day with some rain - bring an umbrella!\n");
   } else {
      printf("The weather today is moderate - enjoy your day!\n");
   }
   
   return 0;
}