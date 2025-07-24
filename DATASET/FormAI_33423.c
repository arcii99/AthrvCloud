//FormAI DATASET v1.0 Category: Pattern printing ; Style: distributed
#include <stdio.h>

int main(){

  int rows;

  printf("Enter number of rows: ");
  scanf("%d", &rows);

  //Printing the upper half of the pattern
  for(int i = 1; i <= rows/2; i++){

    //Printing spaces
    for(int j = 1; j <= rows-i; j++){
      printf(" ");
    }
    
    //Printing stars
    for(int j = 1; j <= (i*2)-1; j++){
      printf("*");
    }

    printf("\n");
  }
  
  //Printing the lower half of the pattern
  for(int i = rows/2; i >= 1; i--){

    //Printing spaces
    for(int j = 1; j <= rows-i; j++){
      printf(" ");
    }
    
    //Printing stars
    for(int j = 1; j <= (i*2)-1; j++){
      printf("*");
    }

    printf("\n");
  }
  
  return 0;
}