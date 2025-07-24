//FormAI DATASET v1.0 Category: Educational ; Style: future-proof
#include <stdio.h>

int main() {
  int num1, num2;
  printf("Enter two numbers: ");
  scanf("%d %d", &num1, &num2);
  
  int gcd = findGCD(num1, num2);
  printf("The gcd of %d and %d is %d", num1, num2, gcd);
  
  return 0;
}

int findGCD(int n1, int n2) {
  int i, gcd;
  for(i=1; i <= n1 && i <= n2; ++i) {
    if(n1%i==0 && n2%i==0)
        gcd = i;
  }
  return gcd;
}