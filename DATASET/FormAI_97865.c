//FormAI DATASET v1.0 Category: Weather simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // initialize random seed with current time
  
  int temperature, humidity, wind_speed, probability_of_rain;
  
  // generate random values for weather parameters
  temperature = rand() % 41 - 10; // range: -10 to 30 degrees Celsius
  humidity = rand() % 101; // range: 0 to 100 percent
  wind_speed = rand() % 101; // range: 0 to 100 km/h
  probability_of_rain = rand() % 101; // range: 0 to 100 percent
  
  // output weather report
  printf("Today's weather report:\n");
  printf("Temperature: %d degrees Celsius\n", temperature);
  printf("Humidity: %d percent\n", humidity);
  printf("Wind speed: %d km/h\n", wind_speed);
  printf("Probability of rain: %d percent\n", probability_of_rain);
  
  // output dress recommendations based on temperature
  if (temperature >= 25) {
    printf("It's hot today. Wear light-colored, loose-fitting clothes.\n");
  } else if (temperature >= 10) {
    printf("It's mild today. Wear a light jacket or sweater.\n");
  } else {
    printf("It's cold today. Dress warmly in layers.\n");
  }
  
  // output umbrella recommendation based on probability of rain
  if (probability_of_rain >= 60) {
    printf("It's likely to rain today. Bring an umbrella with you.\n");
  } else {
    printf("It's unlikely to rain today. You probably don't need an umbrella.\n");
  }
  
  return 0;
}