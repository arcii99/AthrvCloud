//FormAI DATASET v1.0 Category: Robot movement control ; Style: real-life
#include<stdio.h>

int main(){
  int x=0,y=0;  //Initialize x and y to 0
  int key;      //Variable to store the user input
  printf("Welcome to the Robot Movement Control!\n");
  printf("Press 'w' to move forward, 'a' to move left, 'd' to move right, and 's' to move backward\n");
  printf("Press 'q' to quit\n\n");
  while(1){     //Infinite loop until user quits
    printf("Current position: (%d,%d)\n",x,y);
    printf("Enter a key: ");
    key=getchar();    //Read user input
    printf("\n");
    switch(key){      //Switch statement for user input
      case 'w':
        y++;          //Move forward
        break;
      case 'a':
        x--;          //Move left
        break;
      case 'd':
        x++;          //Move right
        break;
      case 's':
        y--;          //Move backward
        break;
      case 'q':
        printf("Exiting Robot Movement Control...\n");
        return 0;     //Quit program
      default:
        printf("Invalid input!\n");
        break;
    }
  }
  return 0;
}