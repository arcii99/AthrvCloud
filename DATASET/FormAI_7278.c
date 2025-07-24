//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: systematic
#include <stdio.h>

void fibonacci(int num){
  int num1 = 0, num2 = 1, next, i;
  printf("\nFibonacci Series up to %d terms: \n", num);

  for(i=0; i<num; i++){
    if(i<=1){
      next = i;
    }
    else{
      next = num1 + num2;
      num1 = num2;
      num2 = next;
    }
    printf("%d ", next);
  }
}

int main(){
  int num;
  printf("Enter the number of terms: ");
  scanf("%d", &num);

  fibonacci(num);

  return 0;
}