//FormAI DATASET v1.0 Category: Robot movement control ; Style: Donald Knuth
#include <stdio.h>

int main() {
  int distance = 0;
  int speed = 0;
  int direction = 1;
  int rotation = 0;
  
  printf("Initializing robot parameters...\n");
  
  while(1) {
    printf("Please input the distance (in cm):\n");
    scanf("%d", &distance);
    printf("Please input the speed (in cm/s):\n");
    scanf("%d", &speed);
    printf("Please input the direction (-1 for reverse, 1 for forward):\n");
    scanf("%d", &direction);
    printf("Please input the rotation angle (in degrees):\n");
    scanf("%d", &rotation);
    
    // Robot movement control goes here
    printf("Moving robot %d cm at %d cm/s, direction %d...\n", distance, speed, direction);
    
    // Robot rotation control goes here
    printf("Rotating robot %d degrees...\n", rotation);
    
    printf("Do you want to continue? (y/n)\n");
    char answer;
    scanf("%c", &answer);
    
    if(answer == 'n' || answer == 'N') {
      printf("Exiting robot movement control program...\n");
      break;
    }
  }
  
  return 0;
}