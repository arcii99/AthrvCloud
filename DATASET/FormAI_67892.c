//FormAI DATASET v1.0 Category: Robot movement control ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int x = 0, y = 0;
  int obstacleX = 3, obstacleY = 3;
  int targetX = 7, targetY = 7;
  int steps = 0;
  
  printf("Starting position: (%d, %d)\n", x, y);
  printf("Obstacle position: (%d, %d)\n", obstacleX, obstacleY);
  printf("Target position: (%d, %d)\n", targetX, targetY);
  
  while (x != targetX || y != targetY) {
    int horizontalMovement = targetX - x;
    int verticalMovement = targetY - y;
    
    if (abs(horizontalMovement) > abs(verticalMovement)) {
      // Move horizontally first
      if (horizontalMovement > 0) {
        // move right
        x++;
        printf("Moved right, ");
      } else {
        // move left
        x--;
        printf("Moved left, ");
      }
      
      if (verticalMovement > 0) {
        // move up
        y++;
        printf("then moved up.\n");
      } else {
        // move down
        y--;
        printf("then moved down.\n");
      }
    } else {
      // Move vertically first
      if (verticalMovement > 0) {
        // move up
        y++;
        printf("Moved up, ");
      } else {
        // move down
        y--;
        printf("Moved down, ");
      }
      
      if (horizontalMovement > 0) {
        // move right
        x++;
        printf("then moved right.\n");
      } else {
        // move left
        x--;
        printf("then moved left.\n");
      }
    }
    
    // Check for obstacle collision
    if (x == obstacleX && y == obstacleY) {
      printf("Obstacle collision detected! Restarting.\n");
      x = y = 0;
      steps = 0;
      continue;
    }
    
    steps++;
  }
  
  printf("Target reached in %d steps.\n", steps);
  
  return 0;
}