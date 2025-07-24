//FormAI DATASET v1.0 Category: Robot movement control ; Style: excited
// Hello there! Are you ready to see me move?
// This is an example C Robot movement control program designed to make you go wow!

#include <stdio.h>
#include <stdlib.h>

// function to move forward
void move_forward(int steps) {
  printf("Moving forward %i steps\n", steps);
  // code to control the robot's forward movement
}

// function to move backward
void move_backward(int steps) {
  printf("Moving backward %i steps\n", steps);
  // code to control the robot's backward movement
}

// function to turn right
void turn_right(int degrees) {
  printf("Turning right %i degrees\n", degrees);
  // code to control the robot's right turn
}

// function to turn left
void turn_left(int degrees) {
  printf("Turning left %i degrees\n", degrees);
  // code to control the robot's left turn
}

int main() {

  // let's start by moving forward 5 steps
  move_forward(5);
  
  // then we'll turn right 90 degrees
  turn_right(90);
  
  // and move forward 3 steps
  move_forward(3);
  
  // now we'll turn left 45 degrees
  turn_left(45);
  
  // and move backward 2 steps
  move_backward(2);
  
  // finally, we'll turn right 180 degrees
  turn_right(180);
  
  // and move forward 10 steps
  move_forward(10);
  
  // wow, that was an amazing display of movement control!
  return 0;
}