//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int r, g, y;
   srand(time(NULL)); // seed rand with current time
   
   printf("Traffic Light Controller Online!\n");
   
   while (1) { // infinite loop
      r = rand()%6 + 5; // random time for red light between 5-10 seconds
      printf("\nRed light on for %d seconds\n", r);
      sleep(r); // pause program for r seconds
      
      g = rand()%11 + 10; // random time for green light between 10-20 seconds
      printf("Green light on for %d seconds\n", g);
      sleep(g); // pause program for g seconds
      
      y = 3; // always have yellow light on for 3 seconds
      printf("Yellow light on for %d seconds\n", y);
      sleep(y); // pause program for y seconds
   }
   
   return 0;
}