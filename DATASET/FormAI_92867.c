//FormAI DATASET v1.0 Category: Robot movement control ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define LEFT 1
#define RIGHT 2
#define FORWARD 3
#define BACKWARD 4

int get_random_direction(){
  return rand() % 4 + 1;
}

bool check_collision(int x, int y, int size, int width, int height){
  if(x < 0 || y < 0 || x + size > width || y + size > height){
    return true;
  }
  else{
    return false;
  }
}

void move_robot(int* x, int* y, int size, int width, int height, int direction){
  switch(direction){
    case LEFT:
      *x -= size;
      break;
    case RIGHT:
      *x += size;
      break;
    case FORWARD:
      *y -= size;
      break;
    case BACKWARD:
      *y += size;
      break;
    default:
      break;
  }
  if(check_collision(*x, *y, size, width, height)){
    switch(direction){
      case LEFT:
        *x += size;
        break;
      case RIGHT:
        *x -= size;
        break;
      case FORWARD:
        *y += size;
        break;
      case BACKWARD:
        *y -= size;
        break;
      default:
        break;
    }
  }
}

int main(){
  srand(time(0));
  int width = 1000, height = 1000, size = 50;
  int x = rand() % (width - size), y = rand() % (height - size);
  int direction = get_random_direction();
  
  while(true){
    move_robot(&x, &y, size, width, height, direction);
    printf("Robot moved to x=%d y=%d\n", x, y);
    direction = get_random_direction();
  }
  
  return 0;
}