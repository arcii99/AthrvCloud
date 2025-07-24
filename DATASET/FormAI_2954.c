//FormAI DATASET v1.0 Category: Temperature monitor ; Style: minimalist
#include <stdio.h>

#define MAX_TEMPERATURES 500 // Maximum number of temperature readings per run

int main() {
  int temperatures[MAX_TEMPERATURES]; // Array to hold temperature readings
  int num_temperatures = 0; // Number of temperature readings entered
  
  // Prompt the user for the temperatures until they enter a non-integer value
  while (1) {
    printf("Enter a temperature value: ");
    int num_args = scanf("%d", &temperatures[num_temperatures]);
    if (num_args != 1) {
      break;
    }
    num_temperatures++;
    
    // If the maximum number of temperatures is reached, exit the loop early
    if (num_temperatures >= MAX_TEMPERATURES) {
      printf("Maximum number of temperatures reached.\n");
      break;
    }
  }
  
  // Calculate the average temperature
  int sum_temperatures = 0;
  for (int i = 0; i < num_temperatures; i++) {
    sum_temperatures += temperatures[i];
  }
  double avg_temperature = (double) sum_temperatures / num_temperatures;
  
  // Print the average temperature
  printf("The average temperature is: %.2f\n", avg_temperature);
  
  return 0;
}