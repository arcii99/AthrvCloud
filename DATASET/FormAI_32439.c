//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: systematic
#include <stdio.h>
#include <stdbool.h>

int main()
{
  int time = 0; // initial time
  bool green_light = true; // set initial light to green
  bool red_light = false;
  
  while (time <= 100) { // run the loop for 100 seconds
    printf("Time: %d seconds\n", time); 
    
    if (green_light) { // if green light is on
      printf("Green light is on\n");
      printf("Yellow light will turn on in 10 seconds\n");
      
      if (time >= 50) { // after 50 seconds
        green_light = false; // turn off green light
        red_light = true; // turn on red light
        printf("Red light is on\n");
        printf("Green light will turn on in 20 seconds\n");
      }
    } 
    else if (red_light) { // if red light is on
      printf("Red light is on\n");
      printf("Yellow light will turn on in 10 seconds\n");
      
      if (time >= 80) { // after 80 seconds
        red_light = false; // turn off red light
        green_light = true; // turn on green light
        printf("Green light is on\n");
      }
    }
    
    time += 10; // increment time by 10 seconds
  }
  
  return 0;
}