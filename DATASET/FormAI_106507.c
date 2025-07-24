//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: inquisitive
#include <stdio.h>

int main() {
  float principle, rate, time, emi, total_interest, total_payment;
  printf("Enter the loan amount: ");
  scanf("%f", &principle);
  printf("Enter the interest rate (in percentage): ");
  scanf("%f", &rate);
  printf("Enter the tenure (in years): ");
  scanf("%f", &time);
  if (principle < 0 || rate < 0 || time < 0) {
    printf("Invalid input entered!");
  } else {
    rate /= 1200;
    time *= 12;
    emi = (principle * rate * pow(1 + rate, time)) / (pow(1 + rate, time) - 1);
    total_payment = emi * time;
    total_interest = total_payment - principle;
    printf("EMI: %.2f\n", emi);
    printf("Total Payment: %.2f\n", total_payment);
    printf("Total Interest: %.2f\n", total_interest);
  }
  return 0;
}