//FormAI DATASET v1.0 Category: Bitwise operations ; Style: light-weight
#include<stdio.h>

int main(){
  int num1 = 10, num2 = 7, result;
  
  // bitwise AND operator
  result = num1 & num2;
  printf("Bitwise AND of %d and %d: %d \n", num1, num2, result);
  
  // bitwise OR operator
  result = num1 | num2;
  printf("Bitwise OR of %d and %d: %d \n", num1, num2, result);
  
  // bitwise XOR operator
  result = num1 ^ num2;
  printf("Bitwise XOR of %d and %d: %d \n", num1, num2, result);
  
  // bitwise complement operator
  result = ~num1;
  printf("Bitwise Complement of %d: %d \n", num1, result);
  
  // left shift operator
  result = num1 << 2;
  printf("%d left shifted by %d: %d \n", num1, 2, result);
  
  // right shift operator
  result = num1 >> 2;
  printf("%d right shifted by %d: %d \n", num1, 2, result);
  
  return 0;
}