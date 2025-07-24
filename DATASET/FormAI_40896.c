//FormAI DATASET v1.0 Category: Temperature monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int temperature;
  srand(time(0)); // initialize random seed
  
  while(1) { // infinite loop
    // generate random temperature between -50 to 50 Celsius
    temperature = rand() % 101 - 50; 
    printf("Temperature: %d Celsius\n", temperature);
    
    if (temperature < -20) {
      printf("Warning: Extremely low temperature. Seek shelter immediately.\n");
    } else if (temperature < 0) {
      printf("Warning: Low temperature. Wear warm clothing.\n");
    } else if (temperature < 20) {
      printf("Normal temperature.\n");
    } else {
      printf("Warning: High temperature. Stay hydrated.\n");
    }
    
    // wait for 5 seconds before checking temperature again
    sleep(5);
  }
  
  return 0;
}