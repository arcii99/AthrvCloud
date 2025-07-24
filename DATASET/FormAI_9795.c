//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: introspective
#include <stdio.h>
#include <string.h>

int main() {
   char user_input[100];
   char command[50];
   int distance;
   int direction;
   int altitude;
   
   while(1) {
      printf("Please enter a command: ");
      fgets(user_input, 100, stdin);
      
      sscanf(user_input, "%s %d %d %d", command, &distance, &direction, &altitude);
      
      if(strcmp(command, "move") == 0) {
         printf("Moving drone %d meters %d degrees at %d meters above ground.\n", distance, direction, altitude);
      } else if(strcmp(command, "takeoff") == 0) {
         printf("Drone taking off to %d meters above ground.\n", altitude);
      } else if(strcmp(command, "land") == 0) {
         printf("Drone landing.\n");
      } else if(strcmp(command, "turn") == 0) {
         printf("Drone turning %d degrees.\n", direction);
      } else if(strcmp(command, "stop") == 0) {
         printf("Stopping drone.\n");
         break;
      } else {
         printf("Invalid command.\n");
      }
   }
   
   return 0;
}