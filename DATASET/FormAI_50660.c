//FormAI DATASET v1.0 Category: Weather simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int humidity(int temp, int windSpeed);

int main() {
  printf("Welcome to the Weather Simulator!\n");
  int temperature = 0;
  int windSpeed = 0;
  int rainProbability = 0;
  int humidityPercentage = 0;
  srand(time(NULL));
  printf("Please enter the current temperature in Celsius: ");
  scanf("%d", &temperature);
  printf("Please enter the current wind speed in km/h: ");
  scanf("%d", &windSpeed);
  printf("\n");

  // Calculate the humidity percentage
  humidityPercentage = humidity(temperature, windSpeed);
  printf("Humidity: %d%%\n", humidityPercentage);

  // Calculate rain probability
  if(humidityPercentage >= 80) {
    if(temperature < 0) {
      rainProbability = 85 + rand()%16;
    } else {
      rainProbability = 70 + rand()%16;
    }
  } else if(humidityPercentage >= 60 && humidityPercentage < 80) {
    if(temperature < 0) {
      rainProbability = 60 + rand()%11;
    } else {
      rainProbability = 45 + rand()%11;
    }
  } else {
    rainProbability = 20 + rand()%11;
  }

  printf("Rain Probability: %d%%\n", rainProbability);
  printf("Thank you for using the Weather Simulator!\n");

  return 0;
}

// Calculates the humidity percentage based on temperature and wind speed
int humidity(int temp, int windSpeed) {
  int humidityPercentage = 0;
  if(temp < -10) {
    humidityPercentage = 90 + rand()%6;
  } else if(temp >= -10 && temp < 0) {
    humidityPercentage = 80 + rand()%11;
  } else if(temp >= 0 && temp < 10) {
    humidityPercentage = 70 + rand()%11;
  } else if(temp >= 10 && temp < 20) {
    humidityPercentage = 60 + rand()%11;
  } else if(temp >= 20 && temp < 30) {
    humidityPercentage = 50 + rand()%11;
  } else if(temp >= 30 && temp < 40) {
    humidityPercentage = 40 + rand()%11;
  } else if(temp >= 40) {
    humidityPercentage = 30 + rand()%11;
  }

  if(windSpeed >= 20 && humidityPercentage > 50) {
    humidityPercentage -= 10;
  }

  return humidityPercentage;
}