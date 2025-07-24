//FormAI DATASET v1.0 Category: Robot movement control ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// function for left movement
void left() {
 printf("Moving Left!\n");
}

// function for right movement
void right() {
 printf("Moving Right!\n");
}

// function for forward movement
void forward() {
 printf("Moving Forward!\n");
}

// function for backward movement
void backward() {
 printf("Moving Backward!\n");
}

int main() {
 int direction = 0;
 printf("Enter direction of movement: \n (1) Left, (2) Right, (3) Forward, (4) Backward -> ");

 // take user input for direction of movement
 scanf("%d", &direction);

 switch(direction) {
  case 1:
   left(); // call left function
   break;
  case 2:
   right(); // call right function
   break;
  case 3:
   forward(); // call forward function
   break;
  case 4:
   backward(); // call backward function
   break;
  default:
   printf("Invalid direction selected!\n"); // error message for invalid direction
 }

 return 0; // end program
}