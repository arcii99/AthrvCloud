//FormAI DATASET v1.0 Category: Pattern printing ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void printC(int rows, int columns, int i, int j){
  if(i==0 || i==rows-1 || j==0){
    printf("*");
  }
  else{
    printf(" ");
  }
  if(j==columns-1){
    printf("\n");
    if(i!=rows-1){
      printC(rows,columns,i+1,0);
    }
  }
  else{
    printC(rows,columns,i,j+1);
  }
}

int main(){
  int rows, columns;
  printf("Enter number of rows: ");
  scanf("%d",&rows);
  printf("Enter number of columns: ");
  scanf("%d",&columns);

  printf("\n");
  printC(rows,columns,0,0);

  return 0;
}