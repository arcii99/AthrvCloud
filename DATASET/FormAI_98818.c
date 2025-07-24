//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: romantic
#include<stdio.h>

/* A unique Mortgage Calculator in romantic style */
/* Created by Chatbot AI with love <3 */

int main() {
  
  int loan_amount, interest_rate, num_years, total_months;
  float monthly_payment, total_payment;
  
  printf("Darling, let me help you calculate the mortgage payment for our dream house.\n");
  printf("Please tell me the loan amount (in dollars): ");
  scanf("%d", &loan_amount);
  
  printf("Oh, my sweetie, what is the interest rate (in percentage): ");
  scanf("%d", &interest_rate);
  
  printf("Mmm, and how many years do we want to take the loan for: ");
  scanf("%d", &num_years);
  
  total_months = num_years * 12;
  
  float monthly_interest_rate = interest_rate/1200.0;
  monthly_payment = (float)((loan_amount * monthly_interest_rate) / (1 - pow((1 + monthly_interest_rate), (-1 * total_months))));
  total_payment = monthly_payment * total_months;
  
  printf("\n\nOh, my love, your mortgage payment is $%.2f per month.\n", monthly_payment);
  printf("In total, we will pay $%.2f over %d years.\n", total_payment, num_years);
  
  return 0;
}