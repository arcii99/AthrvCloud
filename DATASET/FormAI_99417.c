//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Ada Lovelace
//This program is written in Ada Lovelace style, parsing C Syntax
#include <stdio.h>
#include <stdlib.h>

int main() {
  int x = 5, y = 10;
  printf("The value of x is %d and the value of y is %d\n", x, y);
  
  char myChar[] = "Hello, world!";
  printf("%s\n", myChar);
  
  float num1 = 3.14, num2 = 2.718;
  printf("The value of num1 is %f\nThe value of num2 is %f\n", num1, num2);
  
  //if statement example
  if(x < y) {
    printf("x is less than y\n"); 
  } else if (x > y) {
    printf("x is greater than y\n");
  } else {
    printf("x is equal to y\n");
  }
  
  //for loop example
  for(int i = 0; i < 10; i++) {
    printf("%d\n", i);
  }
  
  //while loop example
  int z = 0;
  while(z < 5) {
    printf("z is %d\n", z);
    z++;
  }
  
  //switch statement example
  char grade = 'B';
  switch(grade) {
    case 'A':
      printf("Excellent\n");
      break;
    case 'B':
      printf("Good\n");
      break;
    case 'C':
      printf("Average\n");
      break;
    default:
      printf("Fail\n");
  }
  
  //array example
  int numbers[5] = {1, 2, 3, 4, 5};
  for(int i = 0; i < 5; i++) {
    printf("%d\n", numbers[i]);
  }
  
  //pointer example
  int* ptr;
  ptr = &x;
  printf("The value of x is %d\n", *ptr);
  
  return 0;
}