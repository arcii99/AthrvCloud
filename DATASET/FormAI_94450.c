//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: mathematical
#include<stdio.h>

int main(){
  int map[21][19] = { // The game map is represented by a 2D array
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {0,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,0},
    {0,1,2,1,1,1,2,2,1,1,1,2,2,1,1,1,2,1,0},
    {0,1,2,1,0,0,2,2,2,2,0,2,2,2,0,0,2,1,0}, // 0 represents wall
    {0,1,2,1,0,0,2,1,1,1,0,1,1,1,0,0,2,1,0}, // 1 represents a dot
    {0,1,2,2,2,2,2,1,0,1,2,2,0,1,2,2,2,1,0}, // 2 represents an empty path
    {0,1,1,1,0,0,1,1,0,1,1,0,0,1,1,0,0,1,0},
    {0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,1,0,0,0},
    {0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0},
    {0,0,1,1,0,0,1,1,1,1,1,1,1,0,0,1,1,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,0},
    {0,1,0,0,0,0,0,1,0,1,0,0,1,0,0,0,0,1,0},
    {0,1,0,1,1,1,0,1,0,1,0,0,1,0,1,1,1,1,0},
    {0,1,1,1,0,1,0,1,1,1,1,1,1,0,1,0,0,1,0},
    {0,0,0,1,0,2,0,0,0,0,0,0,0,0,2,0,0,0,0}
  };
  
  /* Pac-Man starting position */
  int pac_x = 1;
  int pac_y = 1;
  
  /* Pac-Man movement direction (0-right, 1-up, 2-left, 3-down)*/
  int direction = 0;
  
  /* Ghosts coordinates and movement directions */
  int ghost_x[4] = {9, 9, 10, 10};
  int ghost_y[4] = {9, 10, 9, 10};
  int ghost_direction[4] = {0, 1, 0, 1};
  
  /* Game loop */
  while(1){
    
    /* Print the game map */
    for(int i=0; i<21; i++){
      for(int j=0; j<19; j++){
        if(i == pac_y && j == pac_x){ // Pac-Man symbol
          printf("P");
        } 
        else if(i == ghost_y[0] && j == ghost_x[0]){ // Ghost 1 symbol
          printf("G");
        }
        else if(i == ghost_y[1] && j == ghost_x[1]){ // Ghost 2 symbol
          printf("G");
        }
        else if(i == ghost_y[2] && j == ghost_x[2]){ // Ghost 3 symbol
          printf("G");
        }
        else if(i == ghost_y[3] && j == ghost_x[3]){ // Ghost 4 symbol
          printf("G");
        }
        else if(map[i][j] == 0){ // Wall symbol
          printf("#");
        }
        else if(map[i][j] == 1){ // Dot symbol
          printf(".");
        }
        else if(map[i][j] == 2){ // Empty path symbol
          printf(" ");
        }
      }
      printf("\n");
    }
    
    /* Pac-Man movement */
    switch(direction){
      case 0: // Move right
        if(map[pac_y][pac_x+1] != 0){
          pac_x++;
        }
        break;
      case 1: // Move up
        if(map[pac_y-1][pac_x] != 0){
          pac_y--;
        }
        break;
      case 2: // Move left
        if(map[pac_y][pac_x-1] != 0){
          pac_x--;
        }
        break;
      case 3: // Move down
        if(map[pac_y+1][pac_x] != 0){
          pac_y++;
        }
        break;
    }
    
    /* Ghosts movement */
    for(int i=0; i<4; i++){
      switch(ghost_direction[i]){
        case 0: // Move right
          if(map[ghost_y[i]][ghost_x[i]+1] != 0){
            ghost_x[i]++;
          } else {
            ghost_direction[i] = 1; // Change direction
          }
          break;
        case 1: // Move up
          if(map[ghost_y[i]-1][ghost_x[i]] != 0){
            ghost_y[i]--;
          } else {
            ghost_direction[i] = 2; // Change direction
          }
          break;
        case 2: // Move left
          if(map[ghost_y[i]][ghost_x[i]-1] != 0){
            ghost_x[i]--;
          } else {
            ghost_direction[i] = 3; // Change direction
          }
          break;
        case 3: // Move down
          if(map[ghost_y[i]+1][ghost_x[i]] != 0){
            ghost_y[i]++;
          } else {
            ghost_direction[i] = 0; // Change direction
          }
          break;
      }
    }
    
    /* Check if Pac-Man captures a dot */
    if(map[pac_y][pac_x] == 1){
      map[pac_y][pac_x] = 2; // Pac-Man eats the dot
    }
    
    /* Check if Pac-Man loses */
    for(int i=0; i<4; i++){
      if(pac_y == ghost_y[i] && pac_x == ghost_x[i]){
        printf("You have lost the game!\n");
        return 0;
      }
    }
    
    /* Check if Pac-Man wins */
    int dots_remaining = 0;
    for(int i=0; i<21; i++){
      for(int j=0; j<19; j++){
        if(map[i][j] == 1){
          dots_remaining++;
        }
      }
    }
    if(dots_remaining == 0){
      printf("Congratulations! You have won the game!\n");
      return 0;
    }
    
    /* Wait for a moment for the game to be readable */
    for(int i=0; i<10000000; i++);
    
    /* Clear the screen and repeat */
    system("clear");
  }
  
  return 0;
}