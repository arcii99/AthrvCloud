//FormAI DATASET v1.0 Category: Weather simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
   // Seed for random number generation
   srand(time(NULL));

   // Variables for weather conditions
   int temperature, humidity;
   float windSpeed, pressure;

   // Generate random weather conditions
   temperature = rand() % 31 - 10; // Temperature range: -10°C to 20°C
   humidity = rand() % 101; // Humidity range: 0% to 100%
   windSpeed = (float)(rand() % 101) / 10; // Wind speed range: 0.0 m/s to 10.0 m/s
   pressure = (float)(rand() % 101 + 1000) / 10; // Pressure range: 100.0 kPa to 110.0 kPa

   // Print weather report
   printf("Weather Report:\n");
   printf("Temperature: %d°C\n", temperature);
   printf("Humidity: %d%%\n", humidity);
   printf("Wind Speed: %.1f m/s\n", windSpeed);
   printf("Pressure: %.1f kPa\n", pressure);

   // Determine weather type based on conditions
   if (temperature < 0) {
      printf("All surfaces are sliding, be careful!\n");
   }
   else if (temperature >= 0 && temperature < 10 && humidity > 90) {
      printf("Very foggy, take caution while driving!\n");
   }
   else if (temperature >= 0 && temperature < 10 && humidity <= 90) {
      printf("Cold and dry, perfect for outdoor activities!\n");
   }
   else if (temperature >= 10 && temperature < 25 && windSpeed < 5 && humidity <= 70) {
      printf("Mild weather, excellent for outdoor activities!\n");
   }
   else if (temperature >= 10 && temperature < 25 && windSpeed >= 5 && humidity <= 70) {
      printf("Slightly breezy, be careful while cycling!\n");
   }
   else if (temperature >= 10 && temperature < 25 && windSpeed < 5 && humidity > 70) {
      printf("Humid and mild, take along an umbrella!\n");
   }
   else if (temperature >= 10 && temperature < 25 && windSpeed >= 5 && humidity > 70) {
      printf("Breezy and humid, take caution while driving!\n");
   }
   else if (temperature >= 25 && windSpeed < 5 && pressure > 103) {
      printf("Hot and high pressure, stay indoors and hydrate!\n");
   }
   else if (temperature >= 25 && windSpeed < 5 && pressure <= 103) {
      printf("Hot and low pressure, stay indoors and hydrate!\n");
   }
   else if (temperature >= 25 && windSpeed >= 5 && pressure > 103) {
      printf("Windy and high pressure, take along a windbreaker!\n");
   }
   else if (temperature >= 25 && windSpeed >= 5 && pressure <= 103) {
      printf("Windy and low pressure, take along a windbreaker and stay hydrated!\n");
   }

   return 0;
}