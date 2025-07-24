//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: brave
#include <stdio.h>
#include <math.h>

int main()
{
    float principle, rate, time, emi;
    int years, months;

    printf("\nEnter the principle amount: ");
    scanf("%f", &principle);

    printf("Enter the rate of interest (in percentage): ");
    scanf("%f", &rate);

    printf("Enter the tenure (in years and months): ");
    scanf("%d %d", &years, &months);

    // calculate the time in years
    time = years + ((float)months / 12);

    // convert the rate of interest from percentage to decimal
    rate = rate / (12 * 100);

    // calculate the EMI using the formula
    emi = (principle * rate * pow(1 + rate, time)) / (pow(1 + rate, time) - 1);

    // calculate the total payable amount
    float payableAmount = emi * (years*12 + months);

    // calculate the interest payable
    float interest = payableAmount - principle;

    // display the result
    printf("\nMortgage details:\n\n");
    printf("Principle amount: %.2f\n", principle);
    printf("Rate of interest: %.2f %%\n", rate*100*12);
    printf("Tenure (in years and months): %d years, %d months\n", years, months);
    printf("EMI per month: %.2f\n", emi);
    printf("Total payable amount: %.2f\n", payableAmount);
    printf("Interest payable: %.2f\n", interest);

    return 0;
}