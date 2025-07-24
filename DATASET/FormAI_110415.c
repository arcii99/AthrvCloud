//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int red = 4, yellow = 1, green = 3;  // time duration for each light in seconds
   int choice = 0;                      // variable to store user's choice
   time_t start;                        // variable to store start time

   while (1) {                          // infinite loop
      printf("\n\nChoose an Option:\n"); // display menu
      printf("1. Traffic Light Simulation\n");
      printf("2. Exit\n\n");
      scanf("%d", &choice);              // read user's choice

      if (choice == 1) {                // traffic light simulation
         start = time(NULL);            // store start time
         printf("\nRED Light");         // red light on
         while (difftime(time(NULL), start) < red) {
            printf(".");
            sleep(1);                  // wait for 1 second
         }
         printf(" -> GREEN Light");     // red light off, green light on
         start = time(NULL);            // reset start time
         while (difftime(time(NULL), start) < green) {
            printf(".");
            sleep(1);                  // wait for 1 second
         }
         printf(" -> YELLOW Light");    // green light off, yellow light on
         start = time(NULL);            // reset start time
         while (difftime(time(NULL), start) < yellow) {
            printf(".");
            sleep(1);                  // wait for 1 second
         }
         printf(" -> RED Light\n\n");   // yellow light off, red light on
      }

      else if (choice == 2) {           // exit program
         printf("\nThank you for using Traffic Light Controller!\n");
         exit(0);
      }

      else {                            // invalid input
         printf("\nInvalid input! Please select option 1 or 2.\n");
      }
   }
   return 0;
}