//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Ken Thompson
/* The following program is a simple temperature monitor */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_TEMP 0
#define MAX_TEMP 100
#define NUM_READINGS 10

int main() {
  int i, temp_sum = 0, temp_average;
  int temp_readings[NUM_READINGS];

  srand(time(NULL)); // get random seed from time

  // generate temperature readings and store in array
  for (i = 0; i < NUM_READINGS; i++) {
    temp_readings[i] = (rand() % (MAX_TEMP - MIN_TEMP + 1)) + MIN_TEMP;
    temp_sum += temp_readings[i];
  }

  temp_average = temp_sum / NUM_READINGS; // calculate average temperature

  // print temperature readings and average
  printf("Temperature Readings:\n");
  for (i = 0; i < NUM_READINGS; i++) {
    printf("%d ", temp_readings[i]);
  }
  printf("\nAverage Temperature: %d\n", temp_average);

  return 0;
}