//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
  int speed = 0, x = 0, y = 0, direction = 0;
  
  printf("Initializing Remote Control Vehicle Simulation...\n");
  printf("Enter desired speed (1-5): ");
  scanf("%d", &speed);
  
  printf("Starting vehicle...\n");
  
  while(1){
    if(direction == 0){
      x += speed;
      printf("Vehicle moved right %d units.\n", speed);
    }else if(direction == 1){
      y += speed;
      printf("Vehicle moved up %d units.\n", speed);
    }else if(direction == 2){
      x -= speed;
      printf("Vehicle moved left %d units.\n", speed);
    }else if(direction == 3){
      y -= speed;
      printf("Vehicle moved down %d units.\n", speed);
    }
    
    printf("Current position: (%d,%d)\n", x, y);
    
    srand(time(NULL));
    direction = rand() % 4;
    printf("New direction: %d\n", direction);
    
    printf("Waiting...\n");
    sleep(1);
  }
  
  return 0;
}