//FormAI DATASET v1.0 Category: Smart home light control ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {
   int lights = 0;
   char input;

   printf("Welcome to Smart Home Light Control!\n");

   while (1) {
      printf("Current light status: %d\n", lights);
      printf("Enter 't' to toggle the lights, 'o' to turn lights on, 'f' to turn lights off, or 'q' to quit: ");
      scanf("%c", &input);

      switch(input) {
         case 't':
            lights = !lights;
            printf("Lights toggled!\n");
            break;
         case 'o':
            lights = 1;
            printf("Lights turned on!\n");
            break;
         case 'f':
            lights = 0;
            printf("Lights turned off!\n");
            break;
         case 'q':
            printf("Exiting Smart Home Light Control...\n");
            exit(0);
         default:
            printf("Invalid input, please try again.\n");
            break;
      }

      // clear input buffer
      while (getchar() != '\n');
   }

   return 0;
}