//FormAI DATASET v1.0 Category: Matrix operations ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

int matrix[ROWS][COLS];

void printMatrix() {
  int i, j;
  
  for(i=0; i<ROWS; i++) {
    for(j=0; j<COLS; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

void addMatrix(int scalar) {
  int i, j;
  
  for(i=0; i<ROWS; i++) {
    for(j=0; j<COLS; j++) {
      matrix[i][j] += scalar;
    }
  }
}

void multiplyMatrix(int scalar) {
  int i, j;
  
  for(i=0; i<ROWS; i++) {
    for(j=0; j<COLS; j++) {
      matrix[i][j] *= scalar;
    }
  }
}

int main() {
  int i, j;
  
  srand(time(NULL));
  
  printf("Initializing Matrix...\n");
  
  for(i=0; i<ROWS; i++) {
    for(j=0; j<COLS; j++) {
      matrix[i][j] = rand() % 10;
    }
  }
  
  printf("Original Matrix\n");
  printMatrix();
  
  printf("Adding 5 to Matrix...\n");
  addMatrix(5);
  printMatrix();
  
  printf("Multiplying Matrix by 2...\n");
  multiplyMatrix(2);
  printMatrix();
  
  return 0;
}