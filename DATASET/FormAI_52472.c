//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: irregular
// Welcome to our unique Mortgage Calculator!

int main() {

  // Declaring our variables
  float total_loan, interest_rate, monthly_payment;
  int years_of_loan;

  printf("Hello! Let's calculate your monthly mortgage payment.\n");
  
  // Asking for user input
  printf("What is the total loan amount ($)? ");
  scanf("%f", &total_loan);
  printf("What is the interest rate (in percentages, e.g. 5.5%%)? ");
  scanf("%f", &interest_rate);
  printf("How many years is the loan? ");
  scanf("%d", &years_of_loan);
  
  // Calculating the monthly payment
  float monthly_interest_rate = interest_rate / 12 / 100;
  int number_of_payments = years_of_loan * 12;
  monthly_payment = monthly_interest_rate * total_loan / (1 - pow(1 + monthly_interest_rate, -number_of_payments));
  
  printf("Your monthly mortgage payment is $%.2f.", monthly_payment);
  
  return 0;
}