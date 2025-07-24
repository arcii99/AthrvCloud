//FormAI DATASET v1.0 Category: Pattern printing ; Style: futuristic
#include<stdio.h>

int main(){

  int rows, cols, height;
  printf("Enter the number of rows: ");
  scanf("%d",&rows);
  printf("Enter the number of columns: ");
  scanf("%d",&cols);
  printf("Enter the height of the pyramid: ");
  scanf("%d",&height);
  
  printf("\n");

  //Printing the top part of pyramid shape
  for(int i=1;i<=rows;i++){
    for(int j=1;j<=cols;j++){
      if(j>=rows-i+1 && j<=rows+i-1){
        printf("@");
      }
      else{
        printf(" ");
      }
    }
    printf("\n");
  }

  printf("\n");

  //Printing the bottom part of pyramid shape
  for(int i=1;i<=height;i++){
    for(int j=1;j<=cols;j++){
      if(j>=rows-i+1 && j<=rows+i-1){
        printf("@");
      }
      else{
        printf(" ");
      }
    }
    printf("\n");
  }

  return 0;
}