//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void generateMaze(int height, int width)
{
  srand(time(NULL)); //initialize random seed
  
  char maze[height][width]; //2D array to store maze
  
  //initialize maze with walls
  for(int i=0;i<height;i++)
  {
    for(int j=0;j<width;j++)
    {
      if(i%2==1 && j%2==1)
        maze[i][j]='.';
      else
        maze[i][j]='X';
    }
  }
  
  //set starting point
  int start_row=1, start_col=0;
  maze[start_row][start_col]=' ';
  
  //set finish point
  int finish_row=height-2, finish_col=width-1;
  maze[finish_row][finish_col]=' ';
  
  //generate maze
  int row=1, col=1;
  int directions[4][2]={{-2,0},{0,2},{2,0},{0,-2}};
  for(int i=0;i<4;i++)
  {
    int r=rand()%4;
    int temp_row=row+directions[r][0];
    int temp_col=col+directions[r][1];
    if(temp_row>=1 && temp_row<height-1 && temp_col>=1 && temp_col<width-1 && maze[temp_row][temp_col]=='X')
    {
      maze[temp_row+directions[r][0]/2][temp_col+directions[r][1]/2]=' ';
      maze[temp_row][temp_col]=' ';
      row=temp_row;
      col=temp_col;
    }
  }
  
  //print maze
  for(int i=0;i<height;i++)
  {
    for(int j=0;j<width;j++)
    {
      printf("%c",maze[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  int height=21, width=21;
  generateMaze(height,width);
  return 0;
}