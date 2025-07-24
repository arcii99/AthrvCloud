//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: active
#include <stdio.h>
#include <math.h>

// function to calculate mortgage payment
double calculateMortgage(double principal, double rate, int term);

int main() {
    // get user input
    double principal, rate;
    int term;
    printf("Enter the principal amount: ");
    scanf("%lf", &principal);
    printf("Enter the interest rate (as a decimal): ");
    scanf("%lf", &rate);
    printf("Enter the term (in years): ");
    scanf("%d", &term);

    // calculate mortgage payment
    double mortgage = calculateMortgage(principal, rate, term);

    // display result
    printf("Your monthly mortgage payment is $%.2f\n", mortgage);

    return 0;
}

double calculateMortgage(double principal, double rate, int term) {
    // convert rate to monthly and term to months
    double monthlyRate = rate / 12;
    int months = term * 12;

    // calculate mortgage payment
    double numerator = principal * monthlyRate * pow((1 + monthlyRate), months);
    double denominator = pow((1 + monthlyRate), months) - 1;
    double mortgage = numerator / denominator;

    return mortgage;
}