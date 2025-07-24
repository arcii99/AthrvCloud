//FormAI DATASET v1.0 Category: Temperature monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  float temp, maxTemp = -273.15, minTemp = 1000;
  int i, n;
  
  srand(time(NULL)); // Initialize random number generator
  
  printf("How many temperature readings would you like to take?: ");
  scanf("%d", &n);
  
  for (i = 1; i <= n; i++) {
    temp = (float) (rand() % 500 - 273) / 10.0 ; // Generate random temperature between -273.0 and 226.9 Celsius
    printf("Temperature Reading %d: %0.1fC\n", i, temp);
    if (temp > maxTemp) { // Update maximum temperature
      maxTemp = temp;
    }
    if (temp < minTemp) { // Update minimum temperature
      minTemp = temp;
    }
  }
  
  printf("Maximum Temperature: %0.1fC\n", maxTemp);
  printf("Minimum Temperature: %0.1fC\n", minTemp);
  
  return 0;
}