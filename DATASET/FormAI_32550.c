//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function declarations
double calculateFutureValue(double, double, int);
double calculateTotalSavings(double, int);
double calculateMonthlySavings(double, int);

int main() {
    // Variable declarations
    double initialAmount, interestRate, futureValue;
    int numYears;

    printf("Welcome to the Personal Finance Planner!\n\n");

    // Get user input for initial amount, interest rate, and number of years
    printf("Please enter the initial amount of the investment: $");
    scanf("%lf", &initialAmount);

    printf("Please enter the annual interest rate (as a decimal): ");
    scanf("%lf", &interestRate);

    printf("Please enter the number of years to invest: ");
    scanf("%d", &numYears);

    // Calculate the future value and print out the result
    futureValue = calculateFutureValue(initialAmount, interestRate, numYears);
    printf("\nThe future value of your investment after %d years is: $%.2lf\n\n", numYears, futureValue);

    // Calculate and print out the total savings and monthly saving needed in order to reach a goal of $1,000,000
    printf("In order to have $1,000,000 in savings after %d years, you will need to save:\n", numYears);

    double totalSavingsNeeded = 1000000.0;
    double totalSavings = calculateTotalSavings(initialAmount, numYears);

    if (totalSavings >= totalSavingsNeeded) {
        printf("$%.2lf in total savings\n", totalSavings);
        printf("and $0 per month if you do not wish to exceed your savings goal.\n\n");
    } else {
        double monthlySavingsNeeded = calculateMonthlySavings(totalSavingsNeeded - totalSavings, numYears);
        printf("$%.2lf in total savings\n", totalSavings);
        printf("and $%.2lf per month if you wish to meet your savings goal.\n\n", monthlySavingsNeeded);
    }

    printf("Thank you for using the Personal Finance Planner!\n");

    return 0;
}

// Function to calculate the future value of an investment
double calculateFutureValue(double initialAmount, double interestRate, int numYears) {
    double exponent = interestRate * numYears;
    double futureValue = initialAmount * pow(1 + interestRate, numYears);
    return futureValue;
}

// Function to calculate the total savings over a given number of years, assuming no additional monthly savings
double calculateTotalSavings(double initialAmount, int numYears) {
    double interestRate = 0.06; // Assumes a 6% annual return
    double totalSavings = initialAmount * pow(1 + interestRate, numYears);
    return totalSavings;
}

// Function to calculate the monthly savings needed to reach a savings goal over a given number of years
double calculateMonthlySavings(double savingsGoal, int numYears) {
    double interestRate = 0.06; // Assumes a 6% annual return
    double numMonths = numYears * 12.0;
    double monthlySavings = (savingsGoal * interestRate) / (pow(1 + interestRate, numMonths) - 1);
    return monthlySavings;
}