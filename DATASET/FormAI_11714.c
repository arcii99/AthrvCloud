//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Ken Thompson
#include<stdio.h>
#include<math.h>

int main(){
    double loanAmount, interestRate, monthlyPayment, totalPayment, balance;
    int numOfMonths, i;
    printf("Enter the loan amount: ");
    scanf("%lf", &loanAmount);
    printf("Enter the interest rate (annual): ");
    scanf("%lf", &interestRate);
    printf("Enter the number of months: ");
    scanf("%d", &numOfMonths);

    double monthlyInterestRate = interestRate / (double) (12 * 100); //Monthly interest rate in decimal
    double numerator = pow((1 + monthlyInterestRate), numOfMonths) * monthlyInterestRate;
    double denominator = pow((1 + monthlyInterestRate), numOfMonths) - 1;
    monthlyPayment = loanAmount * (numerator / denominator); //Calculate the monthly payment amount
    balance = loanAmount;

    printf("\n");
    printf("Monthly Payment: $%.2lf\n", monthlyPayment);
    printf("Total Payment: $%.2lf\n", monthlyPayment * numOfMonths);

    printf("\n");
    printf("Month\tPayment\t\tInterest\tBalance\n");
    printf("------------------------------------------------\n");

    for (i = 0; i < numOfMonths; i++) {
        double interest = balance * monthlyInterestRate; //Calculate the monthly interest amount
        double principal = monthlyPayment - interest; //Calculate the monthly principal amount
        balance = balance - principal; //Calculate the remaining balance
        //Print each payment summary for each month
        printf("%d\t$%.2lf\t\t$%.2lf\t\t$%.2lf\n", i + 1, monthlyPayment, interest, balance);
    }

    return 0;
}