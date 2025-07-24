//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct point {
  int row,col;
};

void maze_output(char maze[][10], int size) {
  printf("\n\n");
  for (int row=0; row<size; row++) {
    for (int col=0; col<size; col++) {
      printf("%c", maze[row][col]);
    }
    printf("\n");
  }
}

void maze_route_printer(struct point route[], int index) {
   for(int i = 0; i < index; i++) {
     printf("(%d,%d)",route[i].row,route[i].col);
   }
   printf("\n\n");
}

void find_route(char maze[][10], int size, struct point start, struct point end, struct point route[], int* found, int index) {
  
  if (start.row == end.row && start.col == end.col) {
    *found = 1;
    maze_route_printer(route, index);
  } else if (start.row >= 0 && start.col >= 0 && start.row < size && start.col <size && maze[start.row][start.col] == '.') {
    maze[start.row][start.col] = '!';
    route[index] = start;
    index++;
    find_route(maze,size,(struct point){start.row-1,start.col},end,route,found,index);
    find_route(maze,size,(struct point){start.row+1,start.col},end,route,found,index);
    find_route(maze,size,(struct point){start.row,start.col-1},end,route,found,index);
    find_route(maze,size,(struct point){start.row,start.col+1},end,route,found,index);
    index--;
    maze[start.row][start.col] = '.';
  }
}

int main() {
  int maze_size = 6,found=0;
  char maze[][10] = {
    {'X','X','X','X','.','X'},
    {'X','.','X','.','.','X'},
    {'X','.','.','.','X','X'},
    {'X','.','X','.','.','X'},
    {'X','#','.','X','.','X'},
    {'X','X','X','X','X','X'}
  };
  struct point start = {0,4}, end = {4,1}, route[maze_size*maze_size];
  find_route(maze,maze_size,start,end,route,&found,0);
  maze_output(maze,maze_size);
  if(!found) printf("\n\n\nNo Route!");
  return 0;
}