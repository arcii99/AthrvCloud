//FormAI DATASET v1.0 Category: Recursive ; Style: peaceful
#include<stdio.h>

int fibonacci(int num);

int main(){
  int n, i;

  printf("Enter the number of terms: ");
  scanf("%d", &n);

  printf("\nFibonacci series:\n");

  for(i=0; i<n; i++){
    printf("%d ", fibonacci(i));
  }

  return 0;
}

int fibonacci(int num){
  if(num == 0){
    return 0;
  }
  else if(num == 1){
    return 1;
  }
  else{
    return (fibonacci(num-1) + fibonacci(num-2));
  }
}