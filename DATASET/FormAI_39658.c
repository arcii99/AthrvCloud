//FormAI DATASET v1.0 Category: Robot movement control ; Style: unmistakable
#include <stdio.h>

int main() {

  int move[4]; //array to store robot movement commands
  
  printf("Welcome to the Robot Movement Control System!\n");
  
  // user input for robot movements
  printf("Please enter the robot movements as follows:\n");
  printf("1 - Move Forward\n");
  printf("2 - Move Backward\n");
  printf("3 - Turn Left\n");
  printf("4 - Turn Right\n");
  
  for(int i = 0; i < 4; i++){
    printf("Movement %d: ", i+1);
    scanf("%d", &move[i]); // store the user input to the array
  }
  
  // Robot movements will start execution
  
  // forward movement
  if(move[0] == 1){
    printf("\nMoving Forward...\n");
  }
  // backward movement
  if(move[1] == 2){
    printf("Moving Backward...\n");
  }
  // left turn movement
  if(move[2] == 3){
    printf("Turning Left...\n");
  }
  // right turn movement
  if(move[3] == 4){
    printf("Turning Right...\n");
  }
  
  printf("\nRobot Movement Completed\n");
  
  return 0;
}