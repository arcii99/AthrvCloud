//FormAI DATASET v1.0 Category: Temperature monitor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  // initialize random seed
  srand(time(0));
  
  int temp[24]; // array to store temperature readings for 24 hours
  int sum = 0; // variable to store sum of temperature readings
  float average; // variable to store average temperature
  int max_temp = 0; // variable to store maximum temperature reading
  
  // fill array with random temperature readings between 0 to 50 degrees Celsius
  for (int i = 0; i < 24; i++) {
    temp[i] = rand() % 51; 
    sum += temp[i]; // calculate sum of readings
    if (temp[i] > max_temp) { // check and update maximum temperature
      max_temp = temp[i];
    }
  }
  
  // calculate average temperature reading
  average = (float)sum/24;
  
  printf("Hour | Temperature Reading (in Celsius)\n");
  for (int i = 0; i < 24; i++) {
    printf("%4d | %d\n", i, temp[i]);
  }
  
  printf("Maximum Temperature Reading: %d Celsius\n", max_temp);
  printf("Average Temperature Reading : %.2f Celsius\n", average);
  
  return 0;
}