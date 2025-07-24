//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: all-encompassing
#include <stdio.h>
#include <math.h>

int main(){
  float principal, rate, time;
  printf("Enter the principal amount: ");
  scanf("%f", &principal);

  printf("Enter the interest rate: ");
  scanf("%f", &rate);

  printf("Enter the time (in years) for duration: ");
  scanf("%f", &time);

  float interest = (principal * rate * time) / 100;
  float monthly_payment = (principal + interest) / (time * 12);
  printf("The monthly payment is %.2f", monthly_payment);

  return 0;
}