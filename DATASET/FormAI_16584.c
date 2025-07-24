//FormAI DATASET v1.0 Category: Weather simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMPERATURE 50
#define MIN_TEMPERATURE -30

int main() {
  srand(time(0)); //seed the random number generator with the current time

  int temperature = rand() % (MAX_TEMPERATURE - MIN_TEMPERATURE + 1) + MIN_TEMPERATURE; //generate a random temperature within the range of -30 to 50 degrees Celsius

  printf("The current temperature is %d degrees Celsius.\n", temperature);

  if (temperature < -20) {
    printf("It is extremly cold today. Please wear your warmest clothes.\n");
  } else if (temperature < 0) {
    printf("It is cold today. Please wear a jacket.\n");
  } else if (temperature < 10) {
    printf("It is cool today. A light jacket should be enough.\n");
  } else if (temperature < 20) {
    printf("It is warm today. T-shirts and shorts are appropriate.\n");
  } else if (temperature < 30) {
    printf("It is hot today. Stay hydrated and wear sunscreen.\n");
  } else {
    printf("It is extremly hot today. Avoid the outdoors if possible.\n");
  }

  return 0;
}