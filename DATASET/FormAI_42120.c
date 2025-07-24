//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: cheerful
#include <stdio.h>

int main() {
    int principal;
    float rate, payment, interest, balance, totalInterest;
    int numPayments;

    // Greet the user and prompt for initial inputs
    printf("Welcome to the Happy Mortgage Calculator!\n");
    printf("What is the principal of the loan? ");
    scanf("%d", &principal);
    printf("What is the interest rate (in percent)? ");
    scanf("%f", &rate);
    printf("What is the number of payments? ");
    scanf("%d", &numPayments);

    // Convert annual interest rate to monthly interest rate
    rate /= 1200;

    // Calculate the fixed payment per month
    payment = (rate * principal) / (1 - pow(1 + rate, -numPayments));

    // Keep track of the payment number and balance for each month
    balance = principal;
    totalInterest = 0;
    printf("\nMonth  Payment  Interest  Principal  Balance\n");
    for (int i = 1; i <= numPayments; i++) {
        interest = balance * rate;
        totalInterest += interest;
        balance = balance + interest - payment;
        printf("%-6d %-8.2f  %-8.2f    %-8.2f    %-8.2f\n", i, payment, interest, payment - interest, balance);
    }

    // Output the results to the user
    printf("\nMonthly Payment: $%.2f\n", payment);
    printf("Total Interest Paid: $%.2f\n", totalInterest);
    printf("Total Payment: $%.2f\n", payment * numPayments);
    printf("Thank you for using the Happy Mortgage Calculator! Have a great day!\n");

    return 0;
}