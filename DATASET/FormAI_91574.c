//FormAI DATASET v1.0 Category: Robot movement control ; Style: standalone
#include <stdio.h>

int main() {
   int pos_x = 0;
   int pos_y = 0;
   int input;
   
   printf("Enter a movement direction (1-4):\n"); // 1 = up, 2 = down, 3 = left, 4 = right
   scanf("%d", &input);
   
   switch (input) {
       case 1:
           pos_y++;
           printf("Moved up.\n");
           break;
       case 2:
           pos_y--;
           printf("Moved down.\n");
           break;
       case 3:
           pos_x--;
           printf("Moved left.\n");
           break;
       case 4:
           pos_x++;
           printf("Moved right.\n");
           break;
       default:
           printf("Invalid input.\n");
           break;
   }
   
   printf("Current position: (%d,%d)\n", pos_x, pos_y);
   
   return 0;
}