//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: irregular
//Irregular Pathfinding Algorithm

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  srand(time(0));
  
  // Building the maze
  int maze[15][15];
  for(int i = 0; i < 15; i++){
    for(int j = 0; j < 15; j++){
      if(i == 0 || i == 14 || j == 0 || j == 14){
        maze[i][j] = 1;
      } else {
        maze[i][j] = rand() % 2;
      }
    }
  }
  
  // Displaying the maze
  printf("Maze:\n");
  for(int i = 0; i < 15; i++){
    for(int j = 0; j < 15; j++){
      printf("%d ", maze[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  
  // Finding the path
  int startX = 1;
  int startY = 1;
  int endX = 13;
  int endY = 13;
  int currX = startX;
  int currY = startY;
  int isBlocked = 0;
  
  printf("Finding path...\n");
  while(currX != endX || currY != endY){
    
    // Checking left
    if(currY > 0 && maze[currX][currY-1] == 0){
      currY--;
      printf("Moved left.\n");
    }
    
    // Checking right
    else if(currY < 14 && maze[currX][currY+1] == 0){
      currY++;
      printf("Moved right.\n");
    }
    
    // Checking up
    else if(currX > 0 && maze[currX-1][currY] == 0){
      currX--;
      printf("Moved up.\n");
    }
    
    // Checking down
    else if(currX < 14 && maze[currX+1][currY] == 0){
      currX++;
      printf("Moved down.\n");
    }
    
    // Stuck
    else {
      isBlocked = 1;
      printf("Blocked.\n");
      break;
    }
  }
  
  if(isBlocked == 0){
    printf("Path found!");
  } else {
    printf("No path found.");
  }
  
  return 0;
}