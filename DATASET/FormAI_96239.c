//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  srand(time(NULL));

  printf("Welcome to the Alien Invasion Probability Calculator!\n");
  
  printf("Enter the current temperature in Celsius: ");
  int temperature;
  if (scanf("%d", &temperature) != 1) {
    printf("Invalid input. Exiting program...\n");
    return 1;
  }
  
  int probability = rand() % 101;
  
  if (temperature < -273) {
    printf("The temperature cannot be below absolute zero. Exiting program...\n");
  } else if (temperature > 5000) {
    printf("The temperature is too high for human habitation. Exiting program...\n");
  } else if (temperature > 100) {
    printf("Warning: The temperature is above boiling point. Alien life forms may not be able to survive. ");
  }
  
  if (probability > 90) {
    printf("Scientists have detected a high probability of alien invasion.\n");
  } else if (probability > 70) {
    printf("There is a moderate probability of alien invasion.\n");
  } else if (probability > 50) {
    printf("Alien invasion is highly unlikely, but not impossible.\n");
  } else {
    printf("Alien invasion probability is very low.\n");
  }

  printf("Thank you for using the Alien Invasion Probability Calculator!\n");

  return 0;
}