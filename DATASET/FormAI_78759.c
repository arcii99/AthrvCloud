//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: interoperable
#include <stdio.h>

// function to calculate monthly payments
double calcMonthlyPayment(double principal, double interestRate, int numYears) {
    double monthlyInterest = interestRate / 1200;
    int numMonths = numYears * 12;
    double numerator = monthlyInterest * pow((1 + monthlyInterest), numMonths);
    double denominator = pow((1 + monthlyInterest), numMonths) - 1;
    double monthlyPayment = principal * (numerator / denominator);
    return monthlyPayment;
}

// function to calculate total interest paid over loan term
double calcTotalInterest(double principal, double interestRate, int numYears) {
    double monthlyPayment = calcMonthlyPayment(principal, interestRate, numYears);
    int numMonths = numYears * 12;
    double totalInterest = (monthlyPayment * numMonths) - principal;
    return totalInterest;
}

int main() {
    double principal, interestRate;
    int numYears;

    printf("Enter the loan principal (in dollars): ");
    scanf("%lf", &principal);

    printf("Enter the loan interest rate (as a percentage): ");
    scanf("%lf", &interestRate);

    printf("Enter the loan term (in years): ");
    scanf("%d", &numYears);

    double monthlyPayment = calcMonthlyPayment(principal, interestRate, numYears);
    double totalInterest = calcTotalInterest(principal, interestRate, numYears);

    printf("\n");
    printf("--------------------\n");
    printf("Loan Information:\n");
    printf("Principal: $%.2f\n", principal);
    printf("Interest Rate: %.2f%%\n", interestRate);
    printf("Term: %d years\n", numYears);
    printf("--------------------\n");
    printf("Monthly Payment: $%.2f\n", monthlyPayment);
    printf("Total Interest Paid: $%.2f\n", totalInterest);
    printf("--------------------\n");

    return 0;
}