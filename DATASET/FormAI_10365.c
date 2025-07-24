//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {

   int ramUsage;

   printf("Starting C RAM Usage Monitor...\n\n");

   while(1) {

      ramUsage = rand() % 100;

      printf("The RAM usage is currently at %d%% surrealism...\n", ramUsage);

      if(ramUsage >= 90) {
         printf("Critical surreal™ level reached. Please evacuate immediately!\n");
      }

      printf("\n\n");

      // Sleep for a surreal amount of time
      usleep(100000);
   }

   return 0;
}