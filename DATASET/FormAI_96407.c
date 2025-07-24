//FormAI DATASET v1.0 Category: Temperature monitor ; Style: mind-bending
#include <stdio.h>

// Defining the temperature limits
#define MIN_TEMP 0
#define MAX_TEMP 100
#define OPT_TEMP 30

// Function to check if the temperature is within limits
int check_temperature(int temp) {
  if (temp < MIN_TEMP) {
    printf("Temperature below minimum limit!\n");
    return -1;
  }
  else if (temp > MAX_TEMP) {
    printf("Temperature above maximum limit!\n");
    return 1;
  }
  else if (temp == OPT_TEMP) {
    printf("Optimal temperature reached!\n");
    return 0;
  }
  else {
    printf("Temperature is within limits.\n");
    return 2;
  }
}

int main() {
  int temp = 25;
  
  printf("Welcome to the temperature monitor program!\n");
  printf("The current temperature is %d degrees Celsius.\n", temp);
  
  int status = check_temperature(temp);
  
  // Keep checking the temperature until optimal temperature is reached
  while (status != 0) {
    printf("Please enter the new temperature reading: ");
    scanf("%d", &temp);
    
    status = check_temperature(temp);
  }
  
  printf("The optimal temperature of %d degrees Celsius has been reached. Shutting down...\n", OPT_TEMP);
  
  return 0;
}