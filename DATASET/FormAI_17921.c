//FormAI DATASET v1.0 Category: Error handling ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int main() {

  double numerator, denominator, result;
  bool error_flag = false;

  printf("Enter numerator: ");
  if(scanf("%lf", &numerator) != 1) {
    printf("Numerator must be a numeric value.\n");
    error_flag = true;
  }

  printf("Enter denominator: ");
  if(scanf("%lf", &denominator) != 1) {
    printf("Denominator must be a numeric value.\n");
    error_flag = true;
  }

  if(denominator == 0) {
    printf("Division by zero is undefined.\n");
    error_flag = true;
  }

  if(!error_flag) {
    result = numerator / denominator;
    printf("Result = %lf\n", result);
  }
  
  return error_flag;
}