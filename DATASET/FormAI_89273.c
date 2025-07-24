//FormAI DATASET v1.0 Category: Recursive ; Style: surprised
#include<stdio.h>
#include<stdlib.h>

int recursiveFunc(int n){
  int result;
  
  if(n == 0){
    result = 1;
  }
  
  else if(n < 0){
    printf("Wait...negative number?!? Whaaat?");
    exit(0);
  }
  
  else{
    printf("Holy recursion, Batman!");
    result = n * recursiveFunc(n-1);
  }
  
  return result;
}

int main(){
  int input, output;
  
  printf("Welcome to the Recursive Surprise program!\n");
  printf("Please input a positive integer: ");
  scanf("%d", &input);
  
  output = recursiveFunc(input);
  printf("The result is: %d", output);
  
  printf("\n\nThanks for using the Recursive Surprise program. Have a nice day!");
  
  return 0;
}