//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: minimalist
#include<stdio.h>
#include<math.h>

int main()
{
    float principle, rate, time, emi, interest, total_amount_payable;
    
    printf("Enter principle amount: ");
    scanf("%f", &principle);
    printf("Enter rate of interest: ");
    scanf("%f", &rate);
    printf("Enter time period in months: ");
    scanf("%f", &time);
    
    // calculating monthly interest rate, EMI and total amount payable
    rate = rate / (12 * 100); 
    emi = (principle * rate * pow(1 + rate, time)) / (pow(1 + rate, time) - 1);
    total_amount_payable = emi * time;
    interest = total_amount_payable - principle;
    
    // displaying the results
    printf("\nMonthly EMI: %.2f\n", emi);
    printf("\nTotal Amount Payable: %.2f\n", total_amount_payable);
    printf("\nTotal Interest Payable: %.2f\n", interest);
    
    return 0;
}