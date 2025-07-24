//FormAI DATASET v1.0 Category: Smart home automation ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

int main()
{
   char command[20];

   while(1)
   {
      printf("Enter Command: ");
      scanf("%s", command);

      if(strcmp(command, "lights-on") == 0)
      {
         // Code to turn on lights
         printf("Lights on!\n");
      }
      else if(strcmp(command, "lights-off") == 0)
      {
         // Code to turn off lights
         printf("Lights off!\n");
      }
      else if(strcmp(command, "fan-on") == 0)
      {
         // Code to turn on fan
         printf("Fan on!\n");
      }
      else if(strcmp(command, "fan-off") == 0)
      {
         // Code to turn off fan
         printf("Fan off!\n");
      }
      else if(strcmp(command, "exit") == 0)
      {
         // Exit the program
         break;
      }
      else
      {
         printf("Unknown command!\n");
      }
   }

   return 0;
}