//FormAI DATASET v1.0 Category: Robot movement control ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define FORWARD 1
#define BACKWARD 2
#define LEFT 3
#define RIGHT 4

void delay(int seconds) {
   int milli_seconds = 1000 * seconds;
   clock_t start_time = clock(); 
   while (clock() < start_time + milli_seconds);
}

int main() {
   int movement;
   int position_x = 0;
   int position_y = 0;

   srand(time(NULL));

   printf("Starting Position: (%d, %d)\n", position_x, position_y);

   while(1) {
      movement = rand() % 4 + 1;
      switch(movement) {
         case FORWARD:
            position_y++;
            printf("Moving Forward\n");
            break;
         case BACKWARD:
            position_y--;
            printf("Moving Backward\n");
            break;
         case LEFT:
            position_x--;
            printf("Turning Left\n");
            break;
         case RIGHT:
            position_x++;
            printf("Turning Right\n");
            break;
      }
      printf("New Position: (%d, %d)\n", position_x, position_y);
      delay(1);
   }
   return 0;
}