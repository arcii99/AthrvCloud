//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Sherlock Holmes
#include <stdio.h>

/* The Case of the Mysterious Mortgage Calculator */

float calculateMonthlyPayments(float principal, float interestRate, int termYears) {
  float monthlyInterest = interestRate / 1200.0;
  int numPayments = termYears * 12;
  float payment = (principal * monthlyInterest) / (1.0 - pow(1.0 + monthlyInterest, -numPayments));
  return payment;
}

int main() {
  printf("Welcome to the Mortgage Calculator, my dear Watson.\n");
  printf("What is the principal amount of the loan?\n");

  float principal;
  scanf("%f", &principal);

  printf("And what is the interest rate?\n");

  float interestRate;
  scanf("%f", &interestRate);

  printf("Lastly, what is the term of the loan in years?\n");

  int termYears;
  scanf("%d", &termYears);

  float monthlyPayment = calculateMonthlyPayments(principal, interestRate, termYears);
  printf("The monthly payment for this loan is $%.2f\n", monthlyPayment);

  printf("But wait, Watson, there's more.\n");
  printf("What if we wanted to see a breakdown of payments over time? How many years should we display?\n");
  
  int displayYears;
  scanf("%d", &displayYears);

  printf("Ah, excellent choice, my friend.\n");
  printf("For your viewing pleasure, I have compiled a table of payments over the next %d years.\n", displayYears);

  printf("|%10s|%15s|%15s|%15s|\n", "Year", "Starting", "Payment", "Ending");
  printf("|%10s|%15s|%15s|%15s|\n", "", "Balance", "Amount", "Balance");

  float balance = principal;
  float interest, principalPaid, totalInterest = 0.0;
  for (int year = 1; year <= displayYears; ++year) {
    printf("|%10d|$%14.2f|", year, balance);
    
    interest = balance * interestRate / 1200.0;
    totalInterest += interest;
    
    if (balance + interest < monthlyPayment) {
      monthlyPayment = balance + interest;
      principalPaid = balance;
      balance = 0.0;
    } else {
      principalPaid = monthlyPayment - interest;
      balance -= principalPaid;
    }
    
    printf("$%14.2f|$", monthlyPayment);
    printf("%14.2f|\n", balance);
  }

  printf("Remarkable, isn't it, Watson?\n");
  printf("We have uncovered the mystery of the mortgage calculator.\n");
  printf("Total interest paid over the life of the loan: $%.2f\n", totalInterest);
  printf("And now we can rest easy knowing all of the financial details of this case.\n");
}