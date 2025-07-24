//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: romantic
#include <stdio.h>

int main() {
   int drone_speed = 0;
   int drone_direction = 0;
   int remote_input = 0;
   
   while(1) {
      printf("Please enter input from the remote: ");
      scanf("%d", &remote_input);
      
      switch (remote_input) {
         case 1:
            drone_speed++;
            break;
         
         case 2:
            drone_speed--;
            break;
         
         case 3:
            drone_direction++;
            break;
         
         case 4:
            drone_direction--;
            break;
         
         default:
            printf("Invalid input!\n");
            continue;
      }
      
      printf("Drone speed: %d\n", drone_speed);
      printf("Drone direction: %d\n", drone_direction);
   }
   
   return 0;
}