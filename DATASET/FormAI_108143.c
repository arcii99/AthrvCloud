//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Ken Thompson
#include <stdio.h>

// function to calculate compound interest
float compound_interest(float principle, float rate, float time)
{
    float interest = principle * (pow((1 + rate / 100), time));
    return interest;
}

// function to calculate total amount
float total_amount(float principle, float rate, float time)
{
    float interest = compound_interest(principle, rate, time);
    float total_amt = principle + interest;
    return total_amt;
}

int main()
{
    printf("Welcome to the Personal Finance Planner\n");

    // input data from user
    float principle, rate, time;
    printf("Enter principle amount: ");
    scanf("%f", &principle);
    printf("Enter rate of interest: ");
    scanf("%f", &rate);
    printf("Enter time period in years: ");
    scanf("%f", &time);

    // calculate and print the compound interest
    float interest = compound_interest(principle, rate, time);
    printf("\nCompound Interest: %.2f\n", interest);

    // calculate and print the total amount
    float total_amt = total_amount(principle, rate, time);
    printf("Total Amount: %.2f\n", total_amt);

    return 0;
}