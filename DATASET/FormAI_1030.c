//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: scientific
#include <stdio.h>
#include <math.h>

double calculateMonthlyPayment(double amount, double interestRate, int term);
double calculateTotalPayment(double monthlyPayment, int term);
double calculateTotalInterest(double totalPayment, double amount);

int main()
{
    double amount, interestRate;
    int term;

    printf("Enter the principal amount: $");
    scanf("%lf", &amount);

    printf("Enter the interest rate per year (as a decimal): ");
    scanf("%lf", &interestRate);

    printf("Enter the loan term in years: ");
    scanf("%d", &term);

    double monthlyPayment = calculateMonthlyPayment(amount, interestRate, term);
    double totalPayment = calculateTotalPayment(monthlyPayment, term);
    double totalInterest = calculateTotalInterest(totalPayment, amount);

    printf("\nLoan Summary:\n");
    printf("Principal Amount: $%.2lf\n", amount);
    printf("Interest Rate: %.2lf%%\n", interestRate * 100);
    printf("Length of Loan: %d years\n", term);
    printf("Monthly Payment: $%.2lf\n", monthlyPayment);
    printf("Total Payment: $%.2lf\n", totalPayment);
    printf("Total Interest: $%.2lf\n", totalInterest);

    return 0;
}

double calculateMonthlyPayment(double amount, double interestRate, int term)
{
    double monthlyRate = interestRate / 12.0;
    int numPayments = term * 12;
    double base = 1.0 + monthlyRate;
    double numerator = amount * monthlyRate * pow(base, numPayments);
    double denominator = pow(base, numPayments) - 1.0;
    return numerator / denominator;
}

double calculateTotalPayment(double monthlyPayment, int term)
{
    return monthlyPayment * term * 12.0;
}

double calculateTotalInterest(double totalPayment, double amount)
{
    return totalPayment - amount;
}