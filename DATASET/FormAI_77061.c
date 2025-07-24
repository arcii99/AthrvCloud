//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: visionary
#include <stdio.h>
#include <math.h>

int main() {
  
  float principle, rate, time, payment, total, interest;
  int n;

  printf("Welcome to the Mortgage Calculator!\n\n");
  
  printf("Please enter the principle amount: ");
  scanf("%f", &principle);
  
  printf("Please enter the interest rate: ");
  scanf("%f", &rate);
  
  printf("Please enter the length of time in years: ");
  scanf("%f", &time);
  
  printf("Please choose the type of payment schedule:\n1. Monthly\n2. Quarterly\n3. Annually\n");
  scanf("%d", &n);
  
  //Calculating the interest rate
  float r = rate/100;
  
  if(n==1){
    r = r/12;
  }
  else if(n==2){
    r = r/4;
  }
  
  //Calculating the total number of payments
  int total_payments = time * n;
  
  //Calculating the payment amount
  float p = pow((1+r), total_payments);
  payment = (principle * (r * p))/(p-1);
  
  //Calculating the total amount paid and the total amount of interest paid
  total = payment * total_payments;
  interest = total - principle;
  
  printf("\nYour monthly payment is: $%.2f\n", payment);
  printf("You will pay a total of: $%.2f\n", total);
  printf("You will pay a total of: $%.2f in interest\n", interest);
  
  return 0;
}