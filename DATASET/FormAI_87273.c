//FormAI DATASET v1.0 Category: Weather simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // initialize random seed based on current time
  int temp = rand()%80 - 20; // generate a random temperature between -20 and 60 degrees Celsius
  int wind_speed = rand()%100; // generate a random wind speed between 0 and 99 km/h
  
  // print out the current weather conditions
  printf("The temperature is %d degrees Celsius and the wind speed is %d km/h.\n", temp, wind_speed);
  
  // determine the weather conditions based on the temperature and wind speed
  if (temp >= 30 && wind_speed >= 50) {
    printf("It's a hot and windy day - be careful and stay hydrated!\n");
  } else if (temp >= 30) {
    printf("It's a hot day - don't forget to wear sunscreen and stay cool!\n");
  } else if (temp < 0 && wind_speed >= 50) {
    printf("It's a freezing and windy day - bundle up and stay warm!\n");
  } else if (temp < 0) {
    printf("It's a freezing day - make sure to wear warm clothing and protect any exposed skin!\n");
  } else if (wind_speed >= 50) {
    printf("It's a windy day - be careful, especially if you're driving or cycling!\n");
  } else {
    printf("It's a mild and pleasant day - enjoy the weather!\n");
  }
  
  return 0;
}