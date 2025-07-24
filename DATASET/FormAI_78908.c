//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: portable
#include <stdio.h>
#include <math.h>

int main()
{
    double principal, interestRate, monthlyPayment, totalPayment, balance;
    int numPayments;
    
    // get user inputs
    printf("Enter Principal amount: ");
    scanf("%lf", &principal);
    printf("Enter Annual Interest Rate: ");
    scanf("%lf", &interestRate);
    printf("Enter Number of Monthly Payments: ");
    scanf("%d", &numPayments);
    
    // calculate monthly payment
    double monthlyRate = interestRate / 1200;
    monthlyPayment = (principal * monthlyRate) / (1 - pow(1 + monthlyRate, -numPayments));
    
    // calculate total payment and balance
    totalPayment = numPayments * monthlyPayment;
    balance = principal;
    printf("\nMonth\tMonthly Payment\tBalance\n");
    for(int i = 1; i <= numPayments; i++)
    {
        double interest = balance * monthlyRate;
        double principalPaid = monthlyPayment - interest;
        balance -= principalPaid;
        printf("%d\t%.2lf\t\t%.2lf\n", i, monthlyPayment, balance);
    }
    
    // print results
    printf("\n-----------------------------------------------\n");
    printf("Loan Summary:\nPrincipal Amount: $%.2lf\nTotal Payment: $%.2lf\n", principal, totalPayment);
    printf("Interest Rate: %.2lf%%\nNumber of Monthly Payments: %d\n", interestRate, numPayments);
    
    return 0;
}