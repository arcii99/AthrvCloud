//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: innovative
#include <stdio.h>
#include <math.h>

int main() {
    float principal, rate, years, emi, temp;
    printf("Enter the Principal amount: ");
    scanf("%f", &principal);
    printf("Enter the Rate of Interest: ");
    scanf("%f", &rate);
    printf("Enter the period in years: ");
    scanf("%f", &years);
    temp = pow((1 + rate), years);
    emi = (principal * rate * temp) / (temp - 1);
    printf("\nMortgage Calculation Results:\n");
    printf("Principal amount: $%.2f\n", principal);
    printf("Rate of Interest: %.2f%%\n", rate);
    printf("Period of Investment: %.2f Years\n\n", years);
    printf("Mortgage EMI per month: $%.2f\n\n", emi);
    printf("Amortization Table:\n");
    printf("%10s %10s %20s %20s %20s\n", "Month", "Principal", "Interest", "EMI", "Balance");
    float balance = principal, total_interest = 0;
    int month;
    for (month = 1; month <= years * 12; month++) {
        float interest = balance * rate / 12;
        float paid_principal = emi - interest;
        balance -= paid_principal;
        total_interest += interest;
        printf("%10d $%10.2f $%20.2f $%20.2f $%20.2f\n", month, paid_principal, interest, emi, balance);
    }
    printf("\n");
    printf("Total Interest paid: $%.2f\n", total_interest);
    printf("Total Payment made: $%.2f\n", total_interest + principal);
    printf("Thank you for using the Mortgage Calculator.\n");
    return 0;
}