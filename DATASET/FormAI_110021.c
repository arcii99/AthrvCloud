//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: sophisticated
#include <stdio.h>

// function to calculate monthly loan payment
float loanPayment(float principle, float rate, int time) {
  float monthly_rate = rate / 1200; //divide by 1200 to convert yearly rate to monthly
  float monthly_payment = (principle * monthly_rate) / (1 - (1 / pow(1 + monthly_rate, time)));
  return monthly_payment;
}

// function to calculate compound interest
float compoundInterest(float principle, float rate, int time) {
  float interest = principle * pow(1 + rate, time) - principle;
  return interest;
}

// function to calculate future value of investment
float futureValue(float principle, float rate, int time) {
  float future = principle * pow(1 + rate, time);
  return future;
}

// main function
int main() {
  float principle;  // amount of money to be borrowed or invested
  float rate;       // annual interest rate
  int time;         // time period in months/years
  int choice;       // user's choice (1 for loan, 2 for investment)

  // ask user for input
  printf("Enter amount of money to be borrowed/invested: ");
  scanf("%f", &principle);
  printf("Enter annual interest rate (in percentage): ");
  scanf("%f", &rate);
  printf("Enter time period (in years): ");
  scanf("%d", &time);

  // ask user for choice (loan or investment)
  printf("Do you want to calculate loan payment or investment return?\n");
  printf("Enter 1 for loan payment, 2 for investment return: ");
  scanf("%d", &choice);

  if(choice == 1) {
    // calculate loan payment
    float monthly_payment = loanPayment(principle, rate, time);
    printf("Monthly loan payment: $%.2f\n", monthly_payment);
  }
  else if(choice == 2) {
    // calculate investment return
    float interest = compoundInterest(principle, rate, time);
    float future = futureValue(principle, rate, time);
    printf("Total interest earned: $%.2f\n", interest);
    printf("Future value of investment: $%.2f\n", future);
  }
  else {
    printf("Invalid choice!\n");
  }

  return 0;
}