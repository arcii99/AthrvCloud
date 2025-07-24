//FormAI DATASET v1.0 Category: Temperature monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  float temperature[10];
  float sum = 0, avg;
  int i, above_avg = 0, below_avg = 0;

  printf("Enter 10 temperatures in Celsius:\n");
  
  // Input temperatures
  for(i=0; i<10; i++) {
    printf("Temperature %d: ", i+1);
    scanf("%f", &temperature[i]);
  }

  // Calculate and display average temperature
  for(i=0; i<10; i++) {
    sum += temperature[i];
  }
  avg = sum/10;
  
  printf("\nAverage temperature: %.2f Celsius\n", avg);

  // Count number of temperatures above and below average
  for(i=0; i<10; i++) {
    if(temperature[i] > avg) {
      above_avg++;
    } else if(temperature[i] < avg) {
      below_avg++;
    }
  }

  // Display number of temperatures above and below average
  printf("\nNumber of temperatures above average: %d\n", above_avg);
  printf("Number of temperatures below average: %d\n", below_avg);

  return EXIT_SUCCESS;
}