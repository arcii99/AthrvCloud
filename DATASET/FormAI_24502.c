//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: modular
#include <stdio.h>

// function to calculate the monthly payment
float calculatePayment(float principle, float interestRate, int months) {
    float rate = interestRate / 1200;  // calculating monthly interest rate
    float payment = (principle * rate) / (1 - (pow(1 / (1 + rate), months)));  // formula to calculate monthly payment
    return payment;
}

// function to calculate the total interest paid
float calculateInterest(float principle, float payment, int months) {
    float totalInterest = (payment * months) - principle;  // formula to calculate total interest
    return totalInterest;
}

// function to display information
void displayInfo(float principle, float interestRate, int months, float payment, float totalInterest) {
    printf("***************************************\n");
    printf("Loan Details:\n");
    printf("***************************************\n");
    printf("Principle Amount: $%.2f\n", principle);
    printf("Interest Rate: %.2f%%\n", interestRate);
    printf("Loan Term: %d months\n", months);
    printf("Monthly Payment: $%.2f\n", payment);
    printf("Total Interest Paid: $%.2f\n", totalInterest);
}

// main function
int main() {
    float principle, interestRate, payment, totalInterest;
    int months;

    // get input from user
    printf("Enter the principle amount: ");
    scanf("%f", &principle);
    printf("Enter the interest rate: ");
    scanf("%f", &interestRate);
    printf("Enter the number of months: ");
    scanf("%d", &months);

    // calculate monthly payment and total interest paid
    payment = calculatePayment(principle, interestRate, months);
    totalInterest = calculateInterest(principle, payment, months);

    // display the loan details
    displayInfo(principle, interestRate, months, payment, totalInterest);

    return 0;
}