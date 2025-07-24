//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: future-proof
#include <stdio.h>

#define MAX 20

int fibonacci[MAX];

void generateFibonacci(){
  fibonacci[0] = 0;
  fibonacci[1] = 1;

  for(int i=2; i<MAX; i++){
    fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
  }
}

void printFibonacci(int size){
  for(int i=0; i<size; i++){
    printf("%d ", fibonacci[i]);
  }
}

void visualizeFibonacci(int size){
  for(int i=0; i<size; i++){
    for(int j=0; j<fibonacci[i]; j++){
      printf("* ");
    }
    printf("\n");
  }
}

int main(){
  generateFibonacci();

  printf("The Fibonacci sequence:\n");
  printFibonacci(MAX);

  printf("\n\nVisualization of the Fibonacci sequence:\n");
  visualizeFibonacci(MAX);

  return 0;
}