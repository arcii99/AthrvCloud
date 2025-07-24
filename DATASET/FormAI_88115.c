//FormAI DATASET v1.0 Category: Robot movement control ; Style: detailed
#include <stdio.h>

int main() {
   int position = 0;   //initialize initial position
   int steps = 0;      //initialize step count
   char direction;     //declare direction variable
   
   while (position < 10 || position > -10){  //continue loop until robot reaches position 10 or -10
      printf("Enter direction (L for left, R for right): ");
      scanf(" %c", &direction);  
    
      if (direction == 'L') {   //if user inputs 'L', move to the left
         position--;
         steps++;
         printf("Step #%d: Moved left\n", steps);
      }
      else if (direction == 'R') {  //if user inputs 'R', move to the right
         position++;
         steps++;
         printf("Step #%d: Moved right\n", steps);
      }
      else {   //if user input is invalid, prompt them to input valid direction
         printf("Invalid direction. Please enter L or R.\n");
      }  
   }
   
   if (position == 10) {  //if robot reaches position 10, print victory message
      printf("Congratulations! You have reached your destination!\n");
   }
   else if (position == -10) {  //if robot reaches position -10, print defeat message
      printf("You have reached the danger zone! Mission failed.\n");
   }
   
   return 0;
}