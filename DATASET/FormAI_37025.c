//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// post-apocalyptic mortgage calculator

int main() {
  float principle, interest_rate, years, monthly_payment, total_interest;
  int num_payments;
  
  printf("Enter the principle amount of the mortgage: ");
  scanf("%f", &principle);
  
  printf("Enter the interest rate: ");
  scanf("%f", &interest_rate);
  
  printf("Enter the number of years: ");
  scanf("%f", &years);
  
  num_payments = years * 12;
  
  interest_rate /= 1200; // convert annual interest rate to monthly
  
  monthly_payment = (principle * interest_rate) / (1 - pow(1 + interest_rate, -num_payments));
  total_interest = monthly_payment * num_payments - principle;
  
  printf("\nAfter %d payments, you will have paid a total of $%.2f\n", num_payments, monthly_payment * num_payments);
  printf("Your monthly payment will be $%.2f\n", monthly_payment);
  printf("In total, you will have paid $%.2f in interest\n\n", total_interest);

  printf("However, in this post-apocalyptic world, payments may not always be made on time...\n");
  printf("Enter the number of missed payments: ");
  
  int missed_payments;
  scanf("%d", &missed_payments);
  
  if (missed_payments > num_payments) {
    printf("\nUnable to calculate. Number of missed payments exceeds the total number of payments.\n\n");
    exit(1);
  }
  
  principle += (monthly_payment * missed_payments);
  
  num_payments -= missed_payments;
  
  monthly_payment = (principle * interest_rate) / (1 - pow(1 + interest_rate, -num_payments));
  total_interest = monthly_payment * num_payments - principle;
  
  printf("\nAfter %d payments, you will have paid a total of $%.2f\n", num_payments + missed_payments, monthly_payment * num_payments + (monthly_payment * missed_payments * 1.25));
  printf("Your monthly payment will be $%.2f (with a 25%% late fee for missed payments)\n", monthly_payment * 1.25);
  printf("In total, you will have paid $%.2f in interest\n\n", total_interest);
  
  return 0;
}