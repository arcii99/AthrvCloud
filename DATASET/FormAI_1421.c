//FormAI DATASET v1.0 Category: Temperature monitor ; Style: thoughtful
#include <stdio.h>

int main() {
  float temp; // Temperature variable
  printf("Enter the current temperature in Celsius: "); // Prompt user to enter temperature
  scanf("%f", &temp); // Store the input value in temp variable

  if(temp >= 37) { // Fever range
    printf("WARNING! You have a fever.\n");
  } else if(temp < 36.5) { // Low temperature range
    printf("WARNING! Your temperature is too low.\n");
  } else { // Normal temperature range
    printf("Your temperature is within the normal range.\n");
  }

  return 0;
}