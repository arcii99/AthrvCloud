//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct {
  int x;
  int y;
} Position;

void move_up(Position* pos) {
  pos->y += 1;
}

void move_down(Position* pos) {
  pos->y -= 1;
}

void move_right(Position* pos) {
  pos->x += 1;
}

void move_left(Position* pos) {
  pos->x -= 1;
}

int main() {
  int direction;
  Position pos = {0, 0};
  srand(time(0));
  
  printf("Remote control vehicle simulation starting...\n");
  
  while(1) {
    // generate a random direction
    direction = rand() % 4;
    
    if(direction == 0) {
      printf("Moving up...\n");
      move_up(&pos);
    } else if(direction == 1) {
      printf("Moving down...\n");
      move_down(&pos);
    } else if(direction == 2) {
      printf("Moving right...\n");
      move_right(&pos);
    } else {
      printf("Moving left...\n");
      move_left(&pos);
    }
    
    printf("Current position: (%d, %d)\n", pos.x, pos.y);
    printf("------------------------------\n");
    
    // add a delay of 1 second
    sleep(1);
  }
  
  return 0;
}