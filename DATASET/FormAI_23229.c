//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>

int main() {
  float principle, rate, time, interest;
  
  printf("Enter the principle amount: ");
  scanf("%f", &principle);
  
  printf("Enter the rate of interest: ");
  scanf("%f", &rate);
  
  printf("Enter the time period (years): ");
  scanf("%f", &time);
  
  interest = principle * rate * time / 100;
  printf("Interest amount: %f\n", interest);
  
  float totalAmount = principle + interest;
  float monthlyAmount = totalAmount / (time * 12);
  printf("Total amount: %f\n", totalAmount);
  printf("Monthly payment amount: %f\n", monthlyAmount);

  return 0;
}