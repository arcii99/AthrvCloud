//FormAI DATASET v1.0 Category: Robot movement control ; Style: enthusiastic
#include <stdio.h>

int main() {
  printf("Welcome to the exciting world of C Robot movement control!\n");
  printf("Let's get started by initializing the robot...\n");
  
  // initialize robot
  int x = 0;
  int y = 0;
  int speed = 10;
  int angle = 0;
  
  // print current position and angle
  printf("Robot current position: x=%d, y=%d\n", x, y);
  printf("Robot current angle: %d degrees\n", angle);
  
  // move forward
  printf("Moving forward...\n");
  x += speed;
  printf("New position: x=%d, y=%d\n", x, y);
  
  // turn right
  printf("Turning right...\n");
  angle += 90;
  printf("New angle: %d degrees\n", angle);
  
  // move forward again
  printf("Moving forward again...\n");
  x += speed;
  printf("New position: x=%d, y=%d\n", x, y);
  
  // turn left
  printf("Turning left...\n");
  angle -= 90;
  printf("New angle: %d degrees\n", angle);
  
  // move backward
  printf("Moving backward...\n");
  y -= speed;
  printf("New position: x=%d, y=%d\n", x, y);
  
  printf("Wow, that was so much fun controlling the C Robot!\n");
  return 0;
}