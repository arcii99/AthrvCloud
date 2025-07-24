//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: all-encompassing
#include <stdio.h>
#include <math.h>

int main(){
    double amount, rate, period, emi, interest, total_amount;
    
    printf("Enter the loan amount: ");
    scanf("%lf", &amount);
    
    printf("Enter the interest rate per annum: ");
    scanf("%lf", &rate);
    
    printf("Enter the loan period in years: ");
    scanf("%lf", &period);
    
    rate = rate / (12 * 100); // converting yearly rate into monthly rate
    period = period * 12;  // converting years into months
    
    emi = (amount * rate * pow(1 + rate, period)) / (pow(1 + rate, period) - 1);
    interest = (emi * period) - amount;
    total_amount = interest + amount;
    
    printf("\n");
    
    printf("Loan Amount: %.2lf\n", amount);
    printf("Interest Rate: %.2lf%%\n", (rate * 12) * 100);
    printf("Loan Period: %.0lf years\n", period/12);
    
    printf("==================================\n");
    
    printf("Monthly EMI: %.2lf\n", emi);
    printf("Total Interest Payable: %.2lf\n", interest);
    printf("Total Amount Payable: %.2lf\n", total_amount);
    
    return 0;
}