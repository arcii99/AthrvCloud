//FormAI DATASET v1.0 Category: Temperature monitor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main() {
   float temperature = 0;
   printf("Welcome to the Temperature Monitor Program.\n");
   while(1) {
      printf("Enter the current temperature (-273.15ºC to 9999ºC): ");
      scanf("%f", &temperature);
      if(temperature < -273.15 || temperature > 9999) {
          printf("Invalid temperature entered. Please try again.\n");  
          continue;
      }
      printf("Temperature entered: %.2fºC\n", temperature);
      if(temperature < 0) {
          printf("Freezing Warning!\n");
      }
      else if(temperature > 100) {
          printf("Boiling Warning!\n");
      }
   }
   return 0;
}