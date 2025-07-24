//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: shape shifting
#include <stdio.h>
#include <math.h>

void printMortgageSummary(double mortgageAmount, double interestRate, double termInYears, double monthlyPayment, double totalPayment) {
    printf("Mortgage Summary:\n");
    printf("--------------------\n");
    printf("Mortgage Amount: $%.2lf\n", mortgageAmount);
    printf("Interest Rate: %.2lf%%\n", interestRate * 100);
    printf("Term: %.0lf years\n", termInYears);
    printf("Monthly Payment: $%.2lf\n", monthlyPayment);
    printf("Total Payment: $%.2lf\n", totalPayment);
    printf("--------------------\n\n");
}

double calculateMonthlyPayment(double mortgageAmount, double interestRate, double termInYears) {
    double monthlyInterestRate = interestRate / 12.0;
    double totalMonths = termInYears * 12.0;
    double numerator = mortgageAmount * monthlyInterestRate * pow(1 + monthlyInterestRate, totalMonths);
    double denominator = pow(1 + monthlyInterestRate, totalMonths) - 1;
    return numerator / denominator;
}

double calculateTotalPayment(double monthlyPayment, double termInYears) {
    return monthlyPayment * termInYears * 12.0;
}

int main() {
    char input[100];
    double mortgageAmount = 0;
    double interestRate = 0;
    double termInYears = 0;
    double monthlyPayment = 0;
    double totalPayment = 0;
    printMortgageSummary(mortgageAmount, interestRate, termInYears, monthlyPayment, totalPayment);

    do {
        printf("Enter mortgage amount: ");
        fgets(input, 100, stdin);
    } while (sscanf(input, "%lf", &mortgageAmount) != 1 || mortgageAmount < 0);

    do {
        printf("Enter interest rate: ");
        fgets(input, 100, stdin);
    } while (sscanf(input, "%lf", &interestRate) != 1 || interestRate < 0);

    do {
        printf("Enter term (in years): ");
        fgets(input, 100, stdin);
    } while (sscanf(input, "%lf", &termInYears) != 1 || termInYears < 0);

    monthlyPayment = calculateMonthlyPayment(mortgageAmount, interestRate / 100, termInYears);
    totalPayment = calculateTotalPayment(monthlyPayment, termInYears);
    printMortgageSummary(mortgageAmount, interestRate, termInYears, monthlyPayment, totalPayment);

    return 0;
}