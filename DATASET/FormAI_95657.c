//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
  int maze[21][21];
  int i,j;
  srand(time(NULL));
  
  // Initializing maze
  for(i=0;i<21;i++)
  {
    for(j=0;j<21;j++)
    {
      if(i%2!=0 && j%2!=0)
        maze[i][j]=0;
      else
        maze[i][j]=1;
    }
  }

  // Generating maze
  int x,y;
  x=rand()%10+1;
  y=1;
  maze[x*2][y*2]=0;
  while(y<9)
  {
    int direction=rand()%3+1;
    if(direction==1 && x!=1)
    {
      x--;
      maze[x*2+2][y*2]=0;
      maze[x*2+1][y*2]=0;
    }
    else if(direction==2 && x!=9)
    {
      x++;
      maze[x*2][y*2+2]=0;
      maze[x*2][y*2+1]=0;
      maze[x*2][y*2-1]=0;      
    }
    else if(direction==3)
    {
      y++;
      maze[x*2][y*2]=0;
      maze[x*2][y*2-1]=0;
    }
  }
  
  // Printing maze
  for(i=0;i<21;i++)
  {
    for(j=0;j<21;j++)
    {
      if(maze[i][j]==0)
        printf(" ");
      else
        printf("#");
    }
    printf("\n");
  }
  return 0;
}