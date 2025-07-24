//FormAI DATASET v1.0 Category: Robot movement control ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_X 10   // Maximum X coordinate
#define MAX_Y 10   // Maximum Y coordinate

typedef struct {
  int x;
  int y;
} Position;

int main() {
  Position robot = {0, 0};   // Robot starts at (0, 0)
  
  srand(time(NULL));   // Initialize random seed
  
  // Loop to move robot randomly
  while(1) {
    int deltaX = rand() % MAX_X - robot.x;
    int deltaY = rand() % MAX_Y - robot.y;
    
    robot.x += deltaX;
    robot.y += deltaY;
    
    printf("Robot moved to (%d, %d)\n", robot.x, robot.y);
    
    // Pause for one second before continuing
    sleep(1);
  }
  
  return 0;
}