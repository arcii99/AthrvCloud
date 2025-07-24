//FormAI DATASET v1.0 Category: Smart home light control ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
   int light_count = 5;
   int light_states[5] = {0, 0, 0, 0, 0}; // all lights are off
   srand(time(NULL)); // Seed the random number generator

   printf("Welcome to Smart Home Light Control program!\n");

   while (1) {
      printf("\nCurrent Light States: ");
      for (int i = 0; i < light_count; i++) {
         printf("%d ", light_states[i]);
      }

      int action = rand() % 4; // select a random action to perform
      int light = rand() % light_count; // select a random light to control

      switch(action) {
         case 0: // turn on light
            if (light_states[light] == 0) {
               printf("\nTurning on Light %d", light+1);
               light_states[light] = 1;
            }
            break;

         case 1: // turn off light
            if (light_states[light] == 1) {
               printf("\nTurning off Light %d", light+1);
               light_states[light] = 0;
            }
            break;

         case 2: // toggle light
            printf("\nToggling Light %d", light+1);
            light_states[light] = !light_states[light];
            break;

         case 3: // do nothing
            printf("\nDoing nothing...");
            break;
      }

      // sleep for 2 seconds so that the user can see the changes
      printf("\nWaiting for 2 seconds...");
      for (int i = 0; i < 2; i++) {
         sleep(1);
         printf(".");
      }
   }

   return 0;
}