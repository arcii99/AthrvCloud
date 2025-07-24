//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: authentic
/* Traffic Light Controller Example Program */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int green_light = 1, yellow_light = 0, red_light = 0; /* Initialize the traffic lights */
  
  srand(time(0)); /* Seed the random number generator */
  
  printf("Traffic Light Controller Program\n\n");
  
  while (1) { /* Loop forever */
    /* Display the current traffic light status */
    printf("Green Light: %d\n", green_light);
    printf("Yellow Light: %d\n", yellow_light);
    printf("Red Light: %d\n\n", red_light);
    
    /* Randomly change the traffic light */
    if (green_light == 1) {
      yellow_light = 1;
      green_light = 0;
    } else if (yellow_light == 1) {
      red_light = 1;
      yellow_light = 0;
    } else if (red_light == 1) {
      green_light = 1;
      red_light = 0;
    }
    
    /* Wait for 3 seconds */
    sleep(3);
  }
  
  return 0;
}