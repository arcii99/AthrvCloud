//FormAI DATASET v1.0 Category: Smart home light control ; Style: invasive
#include <stdio.h>

// Function to turn lights on
void lights_on() {
   printf("Lights turned on.\n");
}

// Function to turn lights off
void lights_off() {
   printf("Lights turned off.\n");
}

// Function to dim the lights
void dim_lights() {
   printf("Lights dimmed.\n");
}

int main() {
   int input;
   printf("Welcome to your smart home light control.\n");
   while (1) {
      printf("Choose an option:\n1 - Toggle lights\n2 - Dim lights\n3 - Exit program\n");
      scanf("%d", &input);
      switch(input) {
         case 1:
            lights_on();
            break;
         case 2:
            dim_lights();
            break;
         case 3:
            printf("Exiting program...");
            return 0;
         default:
            printf("Invalid input. Try again.\n");
            break;
      }
   }
   return 0;
}