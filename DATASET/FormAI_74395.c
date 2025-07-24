//FormAI DATASET v1.0 Category: Robot movement control ; Style: safe
#include<stdio.h>

int main(){
  int x = 0, y = 0;
  char direction = 'N'; //Robot starts at (0,0) facing North
  char command;

  printf("Enter Robot commands: \n");
  while((command = getchar()) != '\n'){
    if(command == 'M'){ //Move robot one unit in current direction
      if(direction == 'N')
        y++; 
      else if(direction == 'E')
        x++;
      else if(direction == 'S')
        y--;
      else if(direction == 'W')
        x--;
    }
    else if(command == 'L'){ //Rotate robot left
      if(direction == 'N')
        direction = 'W';
      else if(direction == 'E')
        direction = 'N';
      else if(direction == 'S')
        direction = 'E';
      else if(direction == 'W')
        direction = 'S';
    }
    else if(command == 'R'){ //Rotate robot right
      if(direction == 'N')
        direction = 'E';
      else if(direction == 'E')
        direction = 'S';
      else if(direction == 'S')
        direction = 'W';
      else if(direction == 'W')
        direction = 'N';
    }
  }

  printf("Robot ended up at (%d,%d) facing %c\n", x, y, direction);
  return 0;
}