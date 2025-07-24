//FormAI DATASET v1.0 Category: Error handling ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

void recursive_function(int num) {
  if(num > 5) {
    printf("Number is greater than 5. Recursive function will exit now.\n");
    return;
  }
  if(num < 0) {
    printf("\n\nError: Entered number is less than 0. Please enter positive numbers only.\n\n");
    exit(0);
  }
  printf("Number = %d\n", num);
  recursive_function(num+1);
}

int main() {
  int num;
  printf("Enter a number between 0 and 5: ");
  scanf("%d", &num);
  recursive_function(num);
  return 0;
}