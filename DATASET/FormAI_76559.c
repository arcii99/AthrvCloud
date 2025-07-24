//FormAI DATASET v1.0 Category: Smart home automation ; Style: introspective
#include <stdio.h>
#include <string.h>

int main()
{
  char command[30];
  int temperature = 20, lights = 0;

  printf("Welcome to Smart Home Automation\n");

  while(1)
  {
      printf("Please say a command: ");
      scanf("%s", command);

      if (strcmp(command, "turn on lights") == 0)
      {
          lights = 1;
          printf("Lights are turned on\n");
      }
      else if (strcmp(command, "turn off lights") == 0)
      {
          lights = 0;
          printf("Lights are turned off\n");
      }
      else if (strcmp(command, "increase temperature") == 0)
      {
          temperature += 1;
          printf("Temperature increased to %d degree Celsius\n", temperature);
      }
      else if (strcmp(command, "decrease temperature") == 0)
      {
          temperature -= 1;
          printf("Temperature decreased to %d degree Celsius\n", temperature);
      }
      else if(strcmp(command, "exit") == 0)
      {
          printf("Thank you for using Smart Home Automation\n");
          break;
      }
      else
      {
          printf("Invalid command! Please try again.\n");
      }
  }

  return 0;
}