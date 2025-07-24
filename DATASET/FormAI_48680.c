//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
  int speed = 0; 
  char command;
  
  printf("Welcome to the Remote control Vehicle Simulation program!\n");
  printf("Use w,a,s,d to drive the vehicle and q to quit.\n");

  while(true){ //continuous loop
    printf("Enter a command: ");
    scanf("%c", &command);

    switch(command) {
      case 'w': 
        printf("Moving forward\n");
        if(speed < 10){
          speed++; //increase speed up to 10
        }
        printf("Current speed: %d\n", speed);
        break;
      case 'a': 
        printf("Turning left\n");
        break;
      case 's': 
        printf("Moving backward\n");
        if(speed > 0){
          speed--; //decrease speed down to 0
        }
        printf("Current speed: %d\n", speed);
        break;
      case 'd': 
        printf("Turning right\n");
        break;
      case 'q': 
        printf("Exiting program\n");
        exit(0); //quit the program
      default:
        printf("Invalid command!\n");
        break;
    }
    //clear input buffer
    while ((getchar()) != '\n');
  } 

  return 0;
}