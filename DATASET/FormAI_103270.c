//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEMP_LIMIT 30.0

int main() {
   float current_temp = 24.5;
   int hours_passed = 0;
   
   srand(time(0));
   
   printf("Temperature monitoring system started...\n");
   while (current_temp < TEMP_LIMIT) {
      printf("Current temperature: %.2f\n", current_temp);
      
      // Simulate temperature changes
      float delta = (float) (rand() % 10 + 1) / 10.0;
      if (rand() % 2 == 0)
         delta *= -1;
      current_temp += delta;
      
      hours_passed++;
   }
   printf("ALERT! Temperature limit exceeded after %d hours\n", hours_passed);
   
   return 0;
}