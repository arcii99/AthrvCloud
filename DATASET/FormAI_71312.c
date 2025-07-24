//FormAI DATASET v1.0 Category: Math exercise ; Style: interoperable
#include <stdio.h>
#include <math.h>

int main() {
  double num1, num2, num3, result1, result2, result3, ans;
  
  printf("Enter first number: ");
  scanf("%lf", &num1);

  printf("Enter second number: ");
  scanf("%lf", &num2);

  printf("Enter third number: ");
  scanf("%lf", &num3);

  result1 = pow(num1, num2);
  result2 = sqrt(num2);
  result3 = cbrt(num3);

  ans = result1 + result2 + result3;

  printf("The result of (%.2lf)^%.2lf + sqrt(%.2lf) + cbrt(%.2lf) is: %.2lf", num1, num2, num2, num3, ans);
  
  return 0;
}