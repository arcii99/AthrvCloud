//FormAI DATASET v1.0 Category: Robot movement control ; Style: curious
#include <stdio.h>

int main() {
   int position = 0;
   printf("Current Position: %d\n", position);
   char move;

   while(1) {
      printf("Move Robot (f-forward, r-right, l-left, b-backward, s-stop): ");
      scanf(" %c", &move);

      switch(move) {
         case 'f':
            position++;
            printf("Robot moved forward. Current Position: %d\n", position);
            break;
         case 'r':
            position += 10;
            printf("Robot turned right. Current Position: %d\n", position);
            break;
         case 'l':
            position -= 10;
            printf("Robot turned left. Current Position: %d\n", position);
            break;
         case 'b':
            position--;
            printf("Robot moved backward. Current Position: %d\n", position);
            break;
         case 's':
            printf("Robot stopped. Final Position: %d\n", position);
            return 0;
         default:
            printf("Invalid move. Try again.\n");
            break;
      }
   }
   return 0;
}