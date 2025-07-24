//FormAI DATASET v1.0 Category: Smart home light control ; Style: random
#include <stdio.h>
#include <stdlib.h>

int main() {
   int brightness = 0;
   int status = 0;
   char input = ' ';
   
   printf("Welcome to the Smart Home Light Control System!\n\n");
   
   while(1) {
      printf("Enter 'o' to turn on the light or 'f' to turn it off: ");
      scanf("%c", &input);
      
      if(input == 'o') {
         printf("Light is now on. Enter brightness level (0-100): ");
         scanf("%d", &brightness);
         
         if(brightness < 0 || brightness > 100) {
            printf("Invalid brightness level. Setting to default (50).\n");
            brightness = 50;
         }
         
         printf("Light brightness set to %d.\n", brightness);
         status = 1;
      }
      else if(input == 'f') {
         printf("Light is now off.\n");
         status = 0;
      }
      else {
         printf("Invalid input.\n");
         continue;
      }
      
      printf("Press 'q' to quit or any other key to continue: ");
      scanf(" %c", &input);
      
      if(input == 'q')
         break;
   }
   
   printf("\nThank you for using the Smart Home Light Control System!\n");
   
   return 0;
}