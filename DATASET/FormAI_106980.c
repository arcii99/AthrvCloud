//FormAI DATASET v1.0 Category: Smart home light control ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   int light_on = 0;
   char command[10];
   printf("Welcome to Smart home Light Control! \n");
   while(1) {
      printf("Enter your command: ");
      scanf("%s", command);
      if(strcmp(command, "turnon") == 0) {
         if(light_on) {
            printf("Light is already ON!\n");
         }
         else {
            printf("Turning ON the Light...\n");
            light_on = 1;
         }
      }
      else if(strcmp(command, "turnoff") == 0) {
         if(!light_on) {
            printf("Light is already OFF!\n");
         }
         else {
            printf("Turning OFF the Light...\n");
            light_on = 0;
         }   
      }
      else if(strcmp(command, "exit") == 0) {
         printf("Goodbye! See you soon.\n");
         break;
      }
      else {
         printf("Unknown command. Please try again.\n");
      }
   }
   return 0;
}