//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: minimalist
#include <stdio.h>

int main () {
   int current_x = 0, current_y = 0;
   int target_x = 50, target_y = 25;
   int distance = 0;

   printf("Current location: (%d, %d)\n", current_x, current_y);

   while (current_x != target_x || current_y != target_y) {
      if (current_x < target_x) {
         current_x++;
      } else if (current_x > target_x) {
         current_x--;
      }

      if (current_y < target_y) {
         current_y++;
      } else if (current_y > target_y) {
         current_y--;
      }

      distance++;

      printf("Current location: (%d, %d)\n", current_x, current_y);
   }

   printf("Target location reached! Total distance travelled: %d\n", distance);

   return 0;
}