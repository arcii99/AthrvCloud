//FormAI DATASET v1.0 Category: Game of Life ; Style: peaceful
#include<stdio.h>
#include<string.h>
#define ROWS 20
#define COLS 20

void print_grid(int grid[ROWS][COLS]){
  printf("\n");
  for(int i=0;i<ROWS;i++){
    for(int j=0;j<COLS;j++){
      if(grid[i][j]==1){
        printf("%c",176);
      }else{
        printf("%c",32);
      }    
    }  
    printf("\n");
  }
}


void update_grid(int grid[ROWS][COLS]){
  int neighbor_count=0;
  int new_grid[ROWS][COLS];
  memcpy(new_grid,grid,sizeof(grid));
  for(int i=0;i<ROWS;i++){
    for(int j=0;j<COLS;j++){
      neighbor_count=0;
      if(i>0){
        if(grid[i-1][j]){ //top        
          neighbor_count++;
        }
        if(j>0){
          if(grid[i-1][j-1]){ //top left      
            neighbor_count++;
          }        
        }
        if(j<COLS-1){
        if(grid[i-1][j+1]){ //top right    
            neighbor_count++;
          }        
        }
      }
      if(j>0){
        if(grid[i][j-1]){ //left
          neighbor_count++;
        }
      }
      if(i<ROWS-1){
        if(grid[i+1][j]){ //bottom
          neighbor_count++;
        }
        if(j>0){
        if(grid[i+1][j-1]){ //bottom left   
            neighbor_count++;
          }        
        }
        if(j<COLS-1){
        if(grid[i+1][j+1]){ //bottom right  
            neighbor_count++;
          }        
        }
      }
      if(j<COLS-1){
        if(grid[i][j+1]){ //right        
          neighbor_count++;
        } 
      }

      if(grid[i][j]){
        if(neighbor_count<2 || neighbor_count>3){
          new_grid[i][j]=0; //cell dies
        }        
      }else{
        if(neighbor_count==3){
          new_grid[i][j]=1; //cell is born
        }
      }

    }  
  }
  memcpy(grid,new_grid,sizeof(grid));
}


int main(){  
  int grid[ROWS][COLS]={{0}};
  grid[4][5]=1;
  grid[5][6]=1;
  grid[6][4]=1;
  grid[6][5]=1;
  grid[6][6]=1;

  while(1){
    print_grid(grid);
    update_grid(grid);
    getchar();
  }  
  return 0;
}