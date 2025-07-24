//FormAI DATASET v1.0 Category: Matrix operations ; Style: puzzling
#include<stdio.h>

int main() {
  int matrix[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
  int i,j,sum;
  printf("Original Matrix:\n");
  for(i=0; i<3; i++){              //printing original matrix
    for(j=0; j<3; j++){
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  printf("Transposed Matrix:\n");
  for(i=0; i<3; i++){              //printing transposed matrix
    for(j=0; j<3; j++){
      printf("%d ", matrix[j][i]);
    }
    printf("\n");
  }
  printf("\n");

  printf("Product of diagonal elements:\n");
  sum=1;
  for(i=0; i<3; i++){              //calculating product of diagonal elements
    sum *= matrix[i][i];
  }
  printf("%d\n",sum);
  printf("\n");

  printf("Rotated Matrix:\n");
  for(i=0; i<3; i++){              //printing rotated matrix
    for(j=0; j<3; j++){
      printf("%d ", matrix[2-j][i]);
    }
    printf("\n");
  }
  printf("\n");

  printf("Symmetric Matrix:\n");
  for(i=0; i<3; i++){              //printing symmetric matrix
    for(j=0; j<3; j++){
      if(matrix[i][j] != matrix[j][i]){
        printf("Not symmetric matrix\n");
        return 0;
      }
    }
  }
  printf("Symmetric matrix\n");
  return 0;
}