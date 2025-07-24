//FormAI DATASET v1.0 Category: Temperature monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   srand(time(NULL)); // seed for random temperature values
   int temp = 0;
   
   printf("Welcome to the Post-Apocalyptic Temperature Monitor!\n\n");
   printf("Monitoring temperature in Celsius...\n\n");

   while(1) { // infinite loop
      temp = rand() % 101 - 50; // range of -50°C to 50°C
      printf("Current temperature: %d°C\n", temp);
      
      if(temp < -20) {
          printf("WARNING: Temperature below -20°C! Seek shelter immediately.\n\n");
      }
      else if(temp < 0) {
          printf("CAUTION: Temperature below freezing. Stay warm.\n\n");
      }
      else if(temp > 40) {
          printf("WARNING: Temperature above 40°C! Seek shelter immediately.\n\n");
      }
      else {
          printf("Temperature within safe range.\n\n");
      }
      
      sleep(5); // wait 5 seconds before checking temperature again
   }
   
   return 0;
}