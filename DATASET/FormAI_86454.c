//FormAI DATASET v1.0 Category: Error handling ; Style: creative
#include <stdio.h>
#include <stdlib.h>

int main(){
  int num1, num2;
  printf("Enter two numbers: ");
  if(scanf("%d %d", &num1, &num2) != 2){ 
    fprintf(stderr, "Error: Invalid input.\n"); 
    exit(EXIT_FAILURE); 
  }
  int result;
  if(num2 == 0){
    fprintf(stderr, "Error: Division by zero.\n"); 
    exit(EXIT_FAILURE); 
  }else{
    result = num1 / num2;
  }
  printf("The result is: %d \n", result);
  return 0;
}