//FormAI DATASET v1.0 Category: Temperature monitor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMPERATURE 45 // maximum temperature in Celsius
#define MIN_TEMPERATURE 5 // minimum temperature in Celsius
#define MAX_READINGS 5 // maximum number of readings to take

int main() {
  float celsius;
  int i = 0;
  float readings[MAX_READINGS];
  float sum = 0;
  float average = 0;

  printf("This program will monitor the temperature in Celsius over the next %d readings.\n", MAX_READINGS);

  while(i < MAX_READINGS) {
    printf("Please enter the temperature in Celsius for reading #%d: ", i+1);
    scanf("%f", &celsius);

    // check if temperature is within acceptable range
    if(celsius >= MIN_TEMPERATURE && celsius <= MAX_TEMPERATURE) {
      readings[i] = celsius;
      sum += celsius;
      i++;
    } else {
      printf("Temperature must be between %d and %d Celsius. Please try again.\n", MIN_TEMPERATURE, MAX_TEMPERATURE);
    }
  }

  average = sum / MAX_READINGS;
  printf("The temperature readings were:\n");

  for(i = 0; i < MAX_READINGS; i++) {
    printf("#%d: %.2f\n", i+1, readings[i]);
  }

  printf("The average temperature over the %d readings was %.2f Celsius.\n", MAX_READINGS, average);

  return 0;
}