//FormAI DATASET v1.0 Category: Arithmetic ; Style: visionary
/*
 * Visionary Arithmetic Example Program
 * Written by [Your Name]
 */

#include <stdio.h>

int main() {
  int a, b, c, d, e, f, g, h, i, j;
  
  printf("Enter ten numbers to perform arithmetic operations: ");
  scanf("%d %d %d %d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g, &h, &i, &j);
  
  int sum = a + b + c + d + e + f + g + h + i + j;
  int product = a * b * c * d * e * f * g * h * i * j;
  int diff = (a - b) - (c - d) - (e - f) - (g - h) - (i - j);
  
  printf("\nThe sum of the ten numbers is: %d", sum);
  printf("\nThe product of the ten numbers is: %d", product);
  printf("\nThe difference of the ten numbers is: %d", diff);
  
  return 0;
}