//FormAI DATASET v1.0 Category: Ebook reader ; Style: mathematical
#include <stdio.h>

// function to calculate the factorial of a number
int factorial(int num) {
  if(num == 1) {
    return 1;
  } else {
    return num * factorial(num-1);
  }
}

int main() {
  int num1, num2, gcd;
  printf("Enter two numbers: ");
  scanf("%d %d", &num1, &num2);
  
  // calculate the gcd of two numbers
  for(int i=1; i<=num1 && i<=num2; i++) {
    if(num1%i == 0 && num2%i == 0) {
      gcd = i;
    }
  }
  
  // calculate the sum of the factorials of two numbers
  int sum = factorial(num1) + factorial(num2);
  
  // calculate the lcm of two numbers
  int lcm;
  if(num1 > num2) {
    lcm = num1;
  } else {
    lcm = num2;
  }
  while(1) {
    if(lcm%num1 == 0 && lcm%num2 == 0) {
      break;
    } else {
      lcm++;
    }
  }
  
  // output the results to the user
  printf("The greatest common divisor of %d and %d is %d.\n", num1, num2, gcd);
  printf("The sum of the factorials of %d and %d is %d.\n", num1, num2, sum);
  printf("The least common multiple of %d and %d is %d.\n", num1, num2, lcm);
  
  return 0;
}