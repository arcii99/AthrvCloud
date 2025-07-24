//FormAI DATASET v1.0 Category: Syntax parsing ; Style: curious
#include<stdio.h>

int main() {
  int num_1, num_2;
  printf("Enter two numbers: ");
  scanf("%d %d", &num_1, &num_2);
  
  if(num_1 > num_2) {
    printf("The first number is greater than the second number.");
  }
  else if(num_2 > num_1) {
    printf("The second number is greater than the first number.");
  }
  else {
    printf("Both numbers are equal.");
  }
  
  return 0;
}