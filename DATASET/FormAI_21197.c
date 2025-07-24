//FormAI DATASET v1.0 Category: Temperature monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

int main() {
  int temperature = 0, temperature_threshold = 25; //set default temperature threshold
  char unit = 'C'; //default temperature unit
  printf("Welcome to the medieval temperature monitor\n");
  printf("Enter the temperature threshold for the kingdom: ");
  scanf("%d", &temperature_threshold);
  printf("Enter the temperature unit for the kingdom (F/C): ");
  scanf(" %c", &unit);
  printf("Temperature threshold set to %d %c\n", temperature_threshold, unit);
  while(1) { //infinite loop
    printf("Enter the current temperature outside the castle: ");
    scanf("%d", &temperature);
    if(unit == 'F') { //if temperature unit is Fahrenheit convert it to Celsius
      temperature = (temperature - 32) * 5 / 9;
    }
    printf("Current temperature is %d %c\n", temperature, unit);
    if(temperature >= temperature_threshold) { //check if temperature exceeds the set threshold
      printf("Oh no! The temperature is too high! Prepare for a scorching summer!\n");
      break; //exit loop
    }
    printf("Everything is well and under control in the kingdom.\n");
  }
  return 0;
}