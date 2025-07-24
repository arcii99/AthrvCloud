//FormAI DATASET v1.0 Category: Weather simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Initialize random number generator
  srand(time(0));

  // Generate random temperatures
  int temperature[7];
  for(int i = 0; i < 7; i++) {
    temperature[i] = rand() % 20 + 10;
  }

  // Displaying the week's temperature
  printf("The temperature for this week is:\n");
  for(int i = 0; i < 7; i++) {
    printf("Day %d: %d degrees Celsius\n", i+1, temperature[i]);
  }

  // Calculate average temperature
  int sum = 0;
  for(int i = 0; i < 7; i++) {
    sum += temperature[i];
  }
  float average = (float)sum / 7;

  // Display average temperature
  printf("The average temperature for this week is %.2f degrees Celsius.\n", average);

  // Determine weather condition
  if(average >= 25) {
    printf("It's scorching hot outside! Make sure to stay hydrated and protect yourself from the sun.\n");
  } else if(average >= 20) {
    printf("It's a warm day outside. Perfect weather for outdoor activities!\n");
  } else if(average >= 15) {
    printf("It's a mild day outside. Comfortable weather for most people.\n");
  } else {
    printf("It's a bit chilly outside. Make sure to dress warmly and protect yourself from the wind.\n");
  }

  return 0;
}