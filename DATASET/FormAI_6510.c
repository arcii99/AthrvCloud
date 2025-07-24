//FormAI DATASET v1.0 Category: Smart home light control ; Style: Donald Knuth
#include <stdio.h>

int main(void)
{
  int light = 0; // initialize light as off

  printf("Welcome to the Smart Home Light Control\n");

  while (1) // infinite loop
  {
    int input;

    printf("Enter 1 to turn on the light or 0 to turn it off: ");
    scanf("%d", &input);

    if (input == 1) // turn the light on
    {
      if (light == 0) // if the light is currently off
      {
        printf("Turning the light on\n");
        light = 1; // update light state to on
      }
      else // if the light is currently on
      {
        printf("The light is already on\n");
      }
    }
    else if (input == 0) // turn the light off
    {
      if (light == 1) // if the light is currently on
      {
        printf("Turning the light off\n");
        light = 0; // update light state to off
      }
      else // if the light is currently off
      {
        printf("The light is already off\n");
      }
    }
    else // invalid input
    {
      printf("Invalid input. Please enter 1 or 0.\n");
    }
  }

  return 0;
}