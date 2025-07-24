//FormAI DATASET v1.0 Category: Smart home light control ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   int light_level = 0;
   char command[10];
   
   while(1) { // loop indefinitely
   
     printf("Enter a command (on, off, dim, bright, exit):\n");
     scanf("%s", command);
     
     if(strcmp(command, "on") == 0) {
        light_level = 100;
        printf("Light on\n");
     } else if(strcmp(command, "off") == 0) {
        light_level = 0;
        printf("Light off\n");
     } else if(strcmp(command, "dim") == 0) {
        if(light_level > 0) 
           light_level = light_level - 25;
        printf("Light dimmed to %d\n", light_level);
     } else if(strcmp(command, "bright") == 0) {
        if(light_level < 100)
           light_level = light_level + 25;
        printf("Light brightened to %d\n", light_level);
     } else if(strcmp(command, "exit") == 0) {
        printf("Exiting program.\n");
        break; // exit loop and end program
     } else {
        printf("Invalid command. Try again.\n");
     }
   } // end of while loop
   
   return 0;
}