//FormAI DATASET v1.0 Category: Robot movement control ; Style: all-encompassing
#include <stdio.h>

int main() {
   int move_direction, distance;
   printf("Welcome to Robot Movement Control Program\n");
   printf("Please provide move direction (1-forward, 2-right, 3-left, 4-backward): ");
   scanf("%d", &move_direction);
   printf("Please provide distance in cm: ");
   scanf("%d", &distance);

   switch (move_direction) {
      case 1:
         printf("Move Forward by %d cm\n", distance);
         break;
      case 2:
         printf("Move Right by %d cm\n", distance);
         break;
      case 3:
         printf("Move Left by %d cm\n", distance);
         break;
      case 4:
         printf("Move Backward by %d cm\n", distance);
         break;
      default:
         printf("Invalid Input\n");
   }
   return 0;
}