//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: creative
#include <stdio.h>

void print_title(){
  printf("------------------------------\n");
  printf("|      Mortgage Calculator   |\n");
  printf("------------------------------\n\n");
}

float get_loan_amount(){
  float loan_amount;
  printf("Enter the loan amount: ");
  scanf("%f", &loan_amount);
  return loan_amount;
}

float get_interest_rate(){
  float interest_rate;
  printf("Enter the interest rate: ");
  scanf("%f", &interest_rate);
  return interest_rate;
}

int get_duration(){
  int duration;
  printf("Enter the duration (in years): ");
  scanf("%d", &duration);
  return duration;
}

float calculate_monthly_payment(float loan_amount, float interest_rate, int duration){
  float monthly_payment;
  float monthly_interest_rate = interest_rate / 1200;
  int num_payments = duration * 12;
  monthly_payment = (loan_amount * monthly_interest_rate) / (1 - pow(1 + monthly_interest_rate, -num_payments));
  return monthly_payment;
}

int main(){
  float loan_amount, interest_rate, monthly_payment;
  int duration;
  
  print_title();
  
  loan_amount = get_loan_amount();
  interest_rate = get_interest_rate();
  duration = get_duration();
  
  monthly_payment = calculate_monthly_payment(loan_amount, interest_rate, duration);

  printf("\n--------------------------------\n");
  printf("|      Mortgage Calculation     |\n");
  printf("--------------------------------\n");
  printf("| Loan Amount:       $%.2f          |\n", loan_amount);
  printf("| Interest Rate:     %.2f%%         |\n", interest_rate);
  printf("| Duration:          %d years       |\n", duration);
  printf("| Monthly Payment:   $%.2f         |\n", monthly_payment);
  printf("--------------------------------\n");

  return 0;
}