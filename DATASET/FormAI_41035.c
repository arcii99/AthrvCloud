//FormAI DATASET v1.0 Category: Temperature monitor ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
  time_t t;
  srand((unsigned) time(&t));
  
  int current_temperature = rand() % 51;
  int reading_count = 0;
  float average_temperature = 0.0;
  
  printf("Welcome to the Brave Temperature Monitor!\n\n");

  while(1) {
    // Update current temperature (random)
    current_temperature = rand() % 51;
    
    printf("Current Temperature: %d\n", current_temperature);
    
    // Increment reading count and update average temperature accordingly
    reading_count++;
    average_temperature = ((average_temperature * (float)(reading_count - 1)) + current_temperature) / (float)reading_count;
    
    printf("Reading Count: %d\n", reading_count);
    printf("Average Temperature: %.2f\n", average_temperature);
    
    // Check if temperature exceeds normal range
    if(current_temperature > 40) {
      printf("\n*** ALERT: Temperature is above normal range! ***\n");
    }
    
    printf("\n");
    
    // Delay for 1 second before getting next reading
    sleep(1);
  }
  
  return 0;
}