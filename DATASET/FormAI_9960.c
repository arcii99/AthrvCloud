//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: post-apocalyptic
#include <stdio.h>

int main() {
  float principal, rate, time, emi, total_amount, interest_amount;

  printf("Enter the principal amount: ");
  scanf("%f", &principal);
  printf("Enter the interest rate: ");
  scanf("%f", &rate);
  printf("Enter the time period (in years): ");
  scanf("%f", &time);

  interest_amount = principal * rate * time;
  total_amount = principal + interest_amount;
  emi = total_amount / (time * 12);

  printf("Total amount: %.2f\n", total_amount);
  printf("EMI: %.2f\n", emi);
  printf("Interest amount: %.2f\n", interest_amount);

  printf("Calculating the mortgage in a post-apocalyptic world...\n");
  
  // Radiation affects the interest rate
  rate += 3.14;
  printf("Interest rate adjusted for radiation: %.2f\n", rate);

  // Scavenging for resources affects the principal amount
  principal -= 5000;
  printf("Principal amount adjusted for resource scavenging: %.2f\n", principal);

  // Bartering for time affects the time period
  time += 2;
  printf("Time period adjusted for bartering: %.2f years\n", time);

  interest_amount = principal * rate * time;
  total_amount = principal + interest_amount;
  emi = total_amount / (time * 12);

  printf("Total amount (post-apocalyptic): %.2f\n", total_amount);
  printf("EMI (post-apocalyptic): %.2f\n", emi);
  printf("Interest amount (post-apocalyptic): %.2f\n", interest_amount);

  return 0;
}