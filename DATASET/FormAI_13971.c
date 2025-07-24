//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Romeo and Juliet
#include <stdio.h>

int main()
{
  int speed = 0;
  int direction = 0;
  
  printf("Welcome to Remote Control Vehicle Simulation!\n");
  printf("Please enter your speed (0-10): ");
  scanf("%d", &speed);
  
  printf("Please enter your direction (0-360): ");
  scanf("%d", &direction);
  
  if(speed > 10 || speed < 0)
  {
    printf("Invalid speed entered. Please try again.\n");
  }
  else if(direction > 360 || direction < 0)
  {
    printf("Invalid direction entered. Please try again.\n");
  }
  else
  {
    printf("Your vehicle is moving at %d speed and %d direction.\n", speed, direction);
  }
  
  return 0;
}