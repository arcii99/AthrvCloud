//FormAI DATASET v1.0 Category: Weather simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // initialize random seed
  srand(time(0));

  // randomly generate temperature
  int temp = rand() % 61 - 20; // temperature ranges from -20 to 40 degrees Celsius
  printf("The current temperature is %d degrees Celsius.\n", temp);

  // randomly generate wind speed
  int windSpd = rand() % 101; // wind speed ranges from 0 to 100 km/h
  int windDir = rand() % 361 - 180; // wind direction ranges from -180 to 180 degrees
  printf("The wind speed is %d km/h and it is blowing towards %d degrees.\n", windSpd, windDir);

  // determine the weather conditions based on the temperature and wind speed
  if (temp >= 30 && windSpd >= 50) {
    printf("It is a scorching hot day with strong winds blowing.\n");
  } else if (temp >= 30 && windSpd < 50) {
    printf("It is a scorching hot day with a light breeze blowing.\n");
  } else if (temp >= 20 && temp < 30 && windSpd >= 50) {
    printf("It is a hot day with strong winds blowing.\n");
  } else if (temp >= 20 && temp < 30 && windSpd < 50) {
    printf("It is a pleasant day with a light breeze blowing.\n");
  } else if (temp >= 10 && temp < 20 && windSpd >= 50) {
    printf("It is a cool day with strong winds blowing.\n");
  } else if (temp >= 10 && temp < 20 && windSpd < 50) {
    printf("It is a cool day with a gentle breeze blowing.\n");
  } else if (temp >= 0 && temp < 10 && windSpd >= 50) {
    printf("It is a chilly day with strong winds blowing.\n");
  } else if (temp >= 0 && temp < 10 && windSpd < 50) {
    printf("It is a chilly day with a light breeze blowing.\n");
  } else if (temp >= -20 && temp < 0 && windSpd >= 50) {
    printf("It is a freezing day with strong winds blowing.\n");
  } else if (temp >= -20 && temp < 0 && windSpd < 50) {
    printf("It is a freezing day with a gentle breeze blowing.\n");
  } else {
    printf("The weather conditions are currently unknown.\n");
  }

  return 0;
}