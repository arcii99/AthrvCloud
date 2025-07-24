//FormAI DATASET v1.0 Category: Temperature monitor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main() {
  int minTemp = -20; 
  int maxTemp = 50;  
  bool warning = false;
  int temp;
  
  srand(time(NULL));  // seed the random number generator with current time
  
  printf("Temperature Monitoring System\n");
  
  while(true) {
    temp = (rand() % (maxTemp - minTemp + 1)) + minTemp;  // generate a random temperature between minTemp and maxTemp
    
    printf("Current Temperature: %d C\n", temp);
    
    if(temp < 0 || temp > 40) {  // check if temperature is outside of acceptable range
      warning = true;
      printf("***WARNING: Temperature outside of acceptable range!***\n");
    }
    
    if(warning && (temp >= 0 && temp <= 40)) {  // check if temperature is back within acceptable range
      warning = false;
      printf("***Temperature back within acceptable range.***\n");
    }
    
    sleep(5);  // wait for 5 seconds before generating next temperature
  }
  
  return 0;
}