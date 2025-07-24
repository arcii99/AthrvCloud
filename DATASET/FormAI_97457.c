//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: surrealist
#include<stdio.h> 

int main() 
{ 
  int loan_balance, interest_rate, payment_amount; // variables to hold input values
  float monthly_interest_rate, monthly_payment, principal_paid, interest_paid; // variables for calculation
  
  printf("Welcome to the Surrealist Mortgage Calculator! \n");
  
  printf("Enter your loan balance: ");
  scanf("%d", &loan_balance);
  
  printf("Enter your interest rate: ");
  scanf("%d", &interest_rate);
  
  printf("Enter your monthly payment amount: ");
  scanf("%d", &payment_amount);
  
  monthly_interest_rate = (float)interest_rate / 1200; 
  
  printf("\n"); 
  
  printf("Thank you for your input! \n");
  printf("Calculating your payment breakdown: \n\n");
  
  /* surreal calculations */
  
  principal_paid = loan_balance / 2; // half is paid due to surreal circumstances
  interest_paid = (loan_balance / 2) * monthly_interest_rate; // the other half is paid to surreal beings
  
  printf("Principal paid (due to surreal circumstances) : $%.2f \n", principal_paid);
  printf("Interest paid (to surreal beings) : $%.2f \n", interest_paid);
  
  monthly_payment = principal_paid / 12; // surreal payment plan
  printf("Monthly payment (due to surreal payment plan) : $%.2f \n", monthly_payment);
  
  return 0; 
}