//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: portable
#include <stdio.h>

void calculate_mortgage(float principal, float interest_rate, int tenure_in_years, float *emi, float *total_interest)
{
    // calculate monthly interest rate
    float r = interest_rate / (12 * 100);

    // calculate total number of months
    int tenure_in_months = tenure_in_years * 12;

    // calculate EMI
    *emi = (principal * r * pow(1 + r, tenure_in_months)) / (pow(1 + r, tenure_in_months) - 1);

    // calculate total interest
    *total_interest = (tenure_in_months * *emi) - principal;
}

int main()
{
    float principal, interest_rate, emi, total_interest;
    int tenure;

    // get principal
    printf("Enter the principal amount: ");
    scanf("%f", &principal);

    // get interest rate
    printf("Enter the interest rate: ");
    scanf("%f", &interest_rate);

    // get tenure in years
    printf("Enter the tenure in years: ");
    scanf("%d", &tenure);

    // calculate EMI and total interest
    calculate_mortgage(principal, interest_rate, tenure, &emi, &total_interest);

    // display EMI and total interest
    printf("EMI: %.2f\n", emi);
    printf("Total interest: %.2f\n", total_interest);

    return 0;
}