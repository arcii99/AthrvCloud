//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: visionary
#include <stdio.h>
#include <math.h>

int main(){
    double principle, rate, time, emi, interest;

    printf("Enter the principle amount: ");
    scanf("%lf", &principle);
    printf("Enter the rate of interest: ");
    scanf("%lf", &rate);
    printf("Enter the time period (in years): ");
    scanf("%lf", &time);

    // Calculating monthly interest rate and number of months
    double i = (rate / 100) / 12;
    double n = time * 12;

    // Calculating EMI
    emi = (principle * i * pow(1 + i, n)) / (pow(1 + i, n) - 1);

    // Calculating total payable amount and total interest
    double total_payable_amount = emi * n;
    interest = total_payable_amount - principle;

    // Printing the details
    printf("\nLoan Details:\n");
    printf("Principle amount: %.2lf\n", principle);
    printf("Rate of interest: %.2lf%%\n", rate);
    printf("Time period (in years): %.2lf\n", time);
    printf("EMI: %.2lf\n", emi);
    printf("Total payable amount: %.2lf\n", total_payable_amount);
    printf("Total interest: %.2lf\n", interest);

    return 0;
}