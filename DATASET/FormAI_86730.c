//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Sherlock Holmes
#include <stdio.h>

int main()
{
    int principal, rate, time, compound, interest;
    float amount;

    printf("Welcome to the Mortgage Calculator\n");
    printf("Please enter the principal amount: ");
    scanf("%d", &principal);

    printf("Please enter the interest rate: ");
    scanf("%d", &rate);

    printf("Please enter the time in years: ");
    scanf("%d", &time);

    printf("Please enter the number of times the interest is compounded in a year: ");
    scanf("%d", &compound);

    interest = rate / 100;
    amount = principal * (pow((1 + interest / compound), compound * time));

    printf("The total amount to be paid is: $%.2f\n", amount);
    printf("Thank you for using the Mortgage Calculator, Mr. Holmes.\n");

    return 0;
}