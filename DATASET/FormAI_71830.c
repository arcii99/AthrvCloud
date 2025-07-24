//FormAI DATASET v1.0 Category: Weather simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); //initialize random seed
  int temperature, humidity, windSpeed, precipitation, thunderstormChance, weatherCode;

  //generate random weather conditions
  temperature = rand() % 50 - 20; //temperature between -20 and 29 degrees celsius
  humidity = rand() % 80 + 20; //humidity between 20% and 100%
  windSpeed = rand() % 30 + 1; //wind speed between 1 and 30 km/h
  precipitation = rand() % 100; //precipitation chance between 0% and 100%
  thunderstormChance = rand() % 100; //thunderstorm chance between 0% and 100%

  //determine weather code based on conditions
  if(precipitation < 30) {
    if(thunderstormChance < 10) {
      weatherCode = 200; //thunderstorm with light rain
    } else {
      weatherCode = 800; //clear sky
    }
  } else if(precipitation < 70) {
    if(thunderstormChance < 30) {
      weatherCode = 201; //thunderstorm with rain
    } else if(windSpeed > 20) {
      weatherCode = 502; //heavy rain and strong wind
    } else {
      weatherCode = 500; //moderate rain
    }
  } else {
    if(thunderstormChance < 60) {
      weatherCode = 202; //thunderstorm with heavy rain
    } else {
      weatherCode = 600; //light snow
    }
  }

  //print out weather report
  printf("Today's weather conditions:\n");
  printf("Temperature: %d degrees Celsius\n", temperature);
  printf("Humidity: %d%%\n", humidity);
  printf("Wind speed: %d km/h\n", windSpeed);
  printf("Precipitation chance: %d%%\n", precipitation);
  printf("Thunderstorm chance: %d%%\n", thunderstormChance);
  printf("Weather code: %d\n", weatherCode);
  
  return 0;
}