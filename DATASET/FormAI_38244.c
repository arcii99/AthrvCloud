//FormAI DATASET v1.0 Category: Arithmetic ; Style: satisfied
#include <stdio.h>

int main() {
  int a, b, c, sum, product, quotient, modulus, difference;

  printf("Enter three integers: ");
  scanf("%d %d %d", &a, &b, &c);

  sum = a + b + c; // Calculate sum
  product = a * b * c; // Calculate product
  quotient = a / b; // Calculate integer quotient
  modulus = a % b; // Calculate modulus
  difference = a - b; // Calculate difference

  printf("Sum = %d\n", sum);
  printf("Product = %d\n", product);
  printf("Quotient = %d\n", quotient);
  printf("Modulus = %d\n", modulus);
  printf("Difference = %d\n", difference);

  return 0;
}