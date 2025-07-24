//FormAI DATASET v1.0 Category: Weather simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Seed the random number generator with the current time
  srand((unsigned) time(NULL));

  // Declare variables for temperature and humidity
  int temperature, humidity;

  // Generate random values for temperature and humidity
  temperature = rand() % 80 - 20; // Temperature range: -20°C to 60°C
  humidity = rand() % 101; // Humidity range: 0% to 100%

  // Determine the weather conditions based on the temperature and humidity
  if (temperature < 0 && humidity < 80) {
    printf("It's cold and dry outside: wear warm clothes!\n");
  } else if (temperature < 0 && humidity >= 80) {
    printf("It's cold and humid outside: watch out for slippery surfaces!\n");
  } else if (temperature >= 0 && temperature <= 15 && humidity < 80) {
    printf("It's cool and dry outside: a light jacket might be needed.\n");
  } else if (temperature >= 0 && temperature <= 15 && humidity >= 80) {
    printf("It's cool and humid outside: it might feel colder than it is, dress accordingly.\n");
  } else if (temperature > 15 && temperature < 25 && humidity < 70) {
    printf("It's a comfortable day outside: enjoy the weather!\n");
  } else if (temperature > 15 && temperature < 25 && humidity >= 70) {
    printf("It's a muggy day outside: drink plenty of water and stay cool.\n");
  } else if (temperature >= 25 && temperature < 35 && humidity < 70) {
    printf("It's a hot and dry day outside: beware of sunburn and dehydration.\n");
  } else if (temperature >= 25 && temperature < 35 && humidity >= 70 && humidity < 90) {
    printf("It's a hot and humid day outside: drink plenty of water and avoid prolonged sun exposure.\n");
  } else if (temperature >= 25 && temperature < 35 && humidity >= 90) {
    printf("It's a sweltering day outside: stay indoors or seek shade if possible.\n");
  } else if (temperature >= 35 && humidity < 70) {
    printf("It's a scorching day outside: drink plenty of water and avoid prolonged sun exposure.\n");
  } else if (temperature >= 35 && humidity >= 70 && humidity < 90) {
    printf("It's a dangerously hot and humid day outside: stay indoors or seek air conditioning if possible.\n");
  } else if (temperature >= 35 && humidity >= 90) {
    printf("It's a life-threatening heat wave outside: seek immediate shelter in air conditioning or a cool location.\n");
  }

  return 0;
}