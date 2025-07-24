//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: minimalist
#include <stdio.h> 

int main() { 
  int speed = 0; 
  int direction = 0; 

  printf("Remote control vehicle simulation\n"); 

  while (1) { 
    printf("Enter speed and direction (0-9): "); 
    scanf("%d %d", &speed, &direction); 

    if (speed == 0 && direction == 0) { 
      printf("Vehicle stopped.\n"); 
    } 
    else { 
      printf("Vehicle moving at speed %d and direction %d\n", speed, direction); 
    } 
  } 

  return 0; 
}