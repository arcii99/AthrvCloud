//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: paranoid
#include <stdio.h>

// function to move the vehicle forward
void forward()
{
  printf("Moving vehicle forward...\n");
}

// function to move the vehicle backward
void backward()
{
  printf("Moving vehicle backward...\n");
}

// function to turn the vehicle left
void left()
{
  printf("Turning vehicle left...\n");
}

// function to turn the vehicle right
void right()
{
  printf("Turning vehicle right...\n");
}

int main()
{
  int input;

  // prompt user for input
  printf("Enter 1 to move forward, 2 to move backward, 3 to turn left, or 4 to turn right: ");
  scanf("%d", &input);

  // perform action based on user input
  switch (input)
  {
    case 1:
      forward();
      break;

    case 2:
      backward();
      break;

    case 3:
      left();
      break;

    case 4:
      right();
      break;

    default:
      printf("Invalid input\n");
      break;
  }

  return 0;
}