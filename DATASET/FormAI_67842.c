//FormAI DATASET v1.0 Category: File handling ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  FILE *fp;
  char file[100], data[100];
  int num1, num2;

  printf("Enter the filename to open: ");
  scanf("%s", file);

  fp = fopen(file, "w+");

  if (fp == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }

  printf("Enter two integers to write to the file: ");
  scanf("%d%d", &num1, &num2);

  fprintf(fp, "%d %d", num1, num2);

  rewind(fp);

  fscanf(fp, "%d %d", &num1, &num2);

  fclose(fp);

  int sum = num1 + num2;
  int difference = num1 - num2;
  int product = num1 * num2;
  double quotient = (double)num1 / num2;
  double power = pow(num1, num2);

  printf("The sum of %d and %d is: %d\n", num1, num2, sum);
  printf("The difference between %d and %d is: %d\n", num1, num2, difference);
  printf("The product of %d and %d is: %d\n", num1, num2, product);
  printf("The quotient of %d and %d is: %.2lf\n", num1, num2, quotient);
  printf("%d raised to the power of %d is: %.2lf", num1, num2, power);

  return 0;
}