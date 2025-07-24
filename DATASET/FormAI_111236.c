//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: secure
#include <stdio.h>
#include <math.h>

double getLoanAmount() {
    double loanAmount;
    printf("Enter Loan Amount: ");
    scanf("%lf", &loanAmount);
    return loanAmount;
}

double getInterestRate() {
    double interestRate;
    printf("Enter Interest Rate (e.g. 5 for 5%%): ");
    scanf("%lf", &interestRate);
    return interestRate / 100.0;
}

double getPeriod() {
    double period;
    printf("Enter period in number of years: ");
    scanf("%lf", &period);
    return period;
}

double calculateMonthlyPayment(double loanAmount, double interestRate, double period) {
    double monthlyInterestRate = interestRate / 12.0;
    double n = period * 12;
    double numerator = loanAmount * monthlyInterestRate * pow(1 + monthlyInterestRate, n);
    double denominator = pow(1 + monthlyInterestRate, n) - 1;
    double monthlyPayment = numerator / denominator;
    return monthlyPayment;
}

int main() {
    printf("********** Welcome to Mortgage Calculator **********\n");
    double loanAmount = getLoanAmount();
    double interestRate = getInterestRate();
    double period = getPeriod();
    double monthlyPayment = calculateMonthlyPayment(loanAmount, interestRate, period);
    printf("\nYour Monthly Payment will be: $%.2lf\n", monthlyPayment);
    return 0;
}