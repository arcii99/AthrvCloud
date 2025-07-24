//FormAI DATASET v1.0 Category: Weather simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to generate random temperature values between -50 and 50
int generateTemperature() {
   return (rand() % (50 - (-50) + 1)) + (-50);
}

//Function to generate random precipitation values between 0 and 100
int generatePrecipitation() {
   return rand() % 101;
}

int main() {
   srand(time(NULL)); //Seed for random number generator

   //Declare Variables
   int temperature, precipitation;
   float humidity;
   char weather[20];

   //Generate Weather Data
   temperature = generateTemperature();
   precipitation = generatePrecipitation();
   humidity = ((float)rand() / RAND_MAX) * 100;
   
   //Determine Weather Conditions
   if (precipitation > 50 && temperature >= 0) {
      sprintf(weather, "Rain");
   }
   else if (precipitation > 50 && temperature < 0) {
      sprintf(weather, "Snow");
   }
   else if (humidity < 50) {
      sprintf(weather, "Dry");
   }
   else if (temperature < 0) {
      sprintf(weather, "Cold");
   }
   else if (temperature >= 0 && temperature < 15) {
      sprintf(weather, "Cool");
   }
   else if (temperature >= 15 && temperature < 25) {
      sprintf(weather, "Moderate");
   }
   else if (temperature >= 25 && temperature <= 35) {
      sprintf(weather, "Warm");
   }
   else {
      sprintf(weather, "Hot");
   }
   
   //Print Weather Data
   printf("Temperature: %d\n", temperature);
   printf("Precipitation: %d%%\n", precipitation);
   printf("Humidity: %.2f%%\n", humidity);
   printf("Weather Conditions: %s", weather);

   return 0;
}