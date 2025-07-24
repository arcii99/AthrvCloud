//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: complex
#include <stdio.h>

//Function to check if remote is connected
void checkRemoteConnection(){
  int remoteConnected = 1;
  
  if(remoteConnected){
    printf("Remote Control Connected!\n");
  }else{
    printf("Remote Control Not Connected!\n");
  }
}

//Function to connect drone to remote
void connectDroneToRemote(){
  printf("Connecting drone to remote control...\n");
  printf("Drone connected to remote control!\n");
}

//Function to take off the drone
void takeOff(){
  int altitude = 0;
  
  printf("Taking off...\n");
  
  //Increase altitude by 10m each second
  for(int i = 0; i < 5; i++){
    altitude += 10;
    printf("Altitude: %d meters\n", altitude);
    sleep(1);
  }
  
  printf("Drone has reached the desired altitude!\n");
}

//Function to move the drone in a specific direction
void moveDrone(char direction){
  switch(direction){
    case 'U':
      printf("Moving the drone UP...\n");
      break;
    case 'D':
      printf("Moving the drone DOWN...\n");
      break;
    case 'L':
      printf("Moving the drone LEFT...\n");
      break;
    case 'R':
      printf("Moving the drone RIGHT...\n");
      break;
    default:
      printf("Invalid direction!\n");
      break;
  }
}

//Function to land the drone
void land(){
  printf("Landing the drone...\n");
  
  int altitude = 50;
  
  //Decrease altitude by 10m each second
  for(int i = 0; i < 5; i++){
    altitude -= 10;
    printf("Altitude: %d meters\n", altitude);
    sleep(1);
  }
  
  printf("Drone has landed safely!\n");
}

int main() {
  checkRemoteConnection();
  
  connectDroneToRemote();
  
  takeOff();
  
  moveDrone('U');
  moveDrone('L');
  moveDrone('R');
  
  land();
  
  return 0;
}