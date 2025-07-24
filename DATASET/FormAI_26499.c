//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10
#define MAX_COMMANDS 5

int x_pos = 0;
int y_pos = 0;

int main() {
  char commands[MAX_COMMANDS];
  srand(time(NULL));
  
  printf("Starting GPS Navigation Simulation\n");
  
  for(int i = 0; i < MAX_COMMANDS; i++) {
    commands[i] = rand() % 4;
  }
  
  printf("Generated Commands: ");
  
  for(int i = 0; i < MAX_COMMANDS; i++) {
    switch(commands[i]) {
      case 0:
        printf("N ");
        y_pos++;
        break;
      case 1:
        printf("S ");
        y_pos--;
        break;
      case 2:
        printf("E ");
        x_pos++;
        break;
      case 3:
        printf("W ");
        x_pos--;
        break;
      default:
        break;
    }
    
    if(x_pos < 0 || x_pos > GRID_SIZE || y_pos < 0 || y_pos > GRID_SIZE) {
      printf("\nOut of Bounds Error!\n");
      return 1;
    }
  }
  
  printf("\nFinal Position: (%d,%d)\n", x_pos, y_pos);
  
  return 0;
}