//FormAI DATASET v1.0 Category: Physics simulation ; Style: recursive
#include <stdio.h>

int ballPosition(int t, int initialPos, int initialVelocity) {
  if (t == 0) { // time == 0
    return initialPos; // the ball's initial position
  }
  else if (t > 0) { // time > 0
    int newPos = initialPos + initialVelocity * t - 16 * t * t; // compute new position using formula of motion
    if (newPos >= 0) { // if the ball is still above ground
      return ballPosition(t - 1, newPos, initialVelocity); // call function recursively with new time and position
    }
    else { // if the ball hits the ground
      return 0;
    }
  }
  else { // invalid input
    printf("Invalid input!");
    return -1;
  }
}

int main() {
  int t, initialPos, initialVelocity;
  printf("Enter time, initial position, and initial velocity: ");
  scanf("%d %d %d", &t, &initialPos, &initialVelocity);
  int finalPos = ballPosition(t, initialPos, initialVelocity); // call function to get final position
  printf("The ball's final position is: %d", finalPos);
  return 0;
}