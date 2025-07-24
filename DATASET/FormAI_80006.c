//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: dynamic
#include<stdio.h>
#include<math.h>

int main()
{
    float principal, interest_rate, time, emi, interest, total_amount;
    int months;
    
    printf("Enter the principal amount: ");
    scanf("%f", &principal);
    printf("Enter the rate of interest per annum: ");
    scanf("%f", &interest_rate);
    printf("Enter the time (in years): ");
    scanf("%f", &time);

    interest_rate = interest_rate / (12 * 100);
    months = time * 12;

    emi = (principal * interest_rate * pow(1 + interest_rate, months)) / (pow(1 + interest_rate, months) - 1);
    interest = emi * months - principal;
    total_amount = emi * months;

    printf("\nThe EMI amount is %.2f\n", emi);
    printf("Total interest payable is %.2f\n", interest);
    printf("Total amount payable is %.2f\n", total_amount);

return 0;
}