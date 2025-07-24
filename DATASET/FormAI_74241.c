//FormAI DATASET v1.0 Category: Robot movement control ; Style: interoperable
#include <stdio.h>

int main(void) {
   int choice, x=0, y=0;
   printf("Welcome to Robot control program. Please enter the following commands: \n");
   printf("1 - Move Forward \n2 - Move Backward \n3 - Turn Left \n4 - Turn Right \n5 - End Program \n");
   scanf("%d",&choice);
   while(choice != 5) {
       switch(choice) {
           case 1:
               printf("Robot is moving forward...\n");
               y++;
               break;
           case 2:
               printf("Robot is moving backward...\n");
               y--;
               break;
           case 3:
               printf("Robot is turning left...\n");
               x--;
               break;
           case 4:
               printf("Robot is turning right...\n");
               x++;
               break;
           default:
               printf("Invalid choice, please enter again.\n");
               break;
       }
       printf("Current position of robot: x=%d, y=%d\n", x, y);
       printf("Please enter command:\n");
       scanf("%d",&choice);
   }
   printf("Program ended successfully.");
   return 0;
}