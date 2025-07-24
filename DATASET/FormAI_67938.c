//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: standalone
#include <stdio.h>

// Function to calculate monthly mortgage payment
double calculateMortgagePayment(double principal, double interestRate, double timeInYears) {
    double monthlyInterestRate = interestRate / 1200.0;
    double numPayments = timeInYears * 12.0;
    double mortgagePayment = (principal * monthlyInterestRate) / (1.0 - pow(1.0 + monthlyInterestRate, -numPayments));
    return mortgagePayment;
}

// Function to calculate compound interest
double calculateCompoundInterest(double principal, double interestRate, double timeInYears) {
    double numCompoundingPeriods = 12.0;
    double compoundedInterestRate = interestRate / 100.0;
    double compoundInterest = principal * pow((1.0 + (compoundedInterestRate / numCompoundingPeriods)), (numCompoundingPeriods * timeInYears)) - principal;
    return compoundInterest;
}

// Function to calculate minimum credit card payment based on APR and balance
double calculateCreditCardMinimumPayment(double balance, double apr) {
    double minimumPayment = balance * 0.02;
    double interest = balance * (apr / 1200.0);
    if (minimumPayment < 15.0) {
        minimumPayment = 15.0;
    }
    if (minimumPayment < interest) {
        minimumPayment = interest;
    }
    return minimumPayment;
}

int main() {
    double principal, interestRate, timeInYears;
    printf("\n====== Welcome to the Personal Finance Planner ======\n");
    printf("Please enter the following info to calculate your monthly mortgage payment:\n");
    printf("Principal: $");
    scanf("%lf", &principal);
    printf("Interest rate: ");
    scanf("%lf", &interestRate);
    printf("Time in years: ");
    scanf("%lf", &timeInYears);
    double mortgagePayment = calculateMortgagePayment(principal, interestRate, timeInYears);
    printf("Your monthly mortgage payment is: $%.2lf\n\n", mortgagePayment);

    double compoundInterestRate, compoundedBalance, timeInMonths;
    printf("Please enter the following info to calculate your compound interest on a savings account:\n");
    printf("Principal: $");
    scanf("%lf", &principal);
    printf("Annual interest rate: ");
    scanf("%lf", &compoundInterestRate);
    printf("Time in years: ");
    scanf("%lf", &timeInYears);
    double compoundInterest = calculateCompoundInterest(principal, compoundInterestRate, timeInYears);
    printf("Your total compound interest over %d years is: $%.2lf\n\n", (int) timeInYears, compoundInterest);

    double creditCardBalance, creditCardAPR;
    printf("Please enter the following info to calculate your minimum monthly credit card payment:\n");
    printf("Credit card balance: $");
    scanf("%lf", &creditCardBalance);
    printf("Annual percentage rate (APR): ");
    scanf("%lf", &creditCardAPR);
    double creditCardMinimumPayment = calculateCreditCardMinimumPayment(creditCardBalance, creditCardAPR);
    printf("Your minimum monthly credit card payment is: $%.2lf\n", creditCardMinimumPayment);

    printf("\nThank you for using the Personal Finance Planner!\n\n");
    return 0;
}