//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    float principle_amount, interest_rate, monthly_payment, total_amount;
    int years, months;
    printf("Welcome to our Mortgage Calculator!\n");
    printf("Enter the Principle amount: ");
    scanf("%f", &principle_amount);
    printf("Enter the interest rate: ");
    scanf("%f", &interest_rate);
    printf("Enter the duration of loan (in years): ");
    scanf("%d", &years);

    months = years * 12;
    interest_rate = interest_rate/1200;
    monthly_payment = (principle_amount*interest_rate*pow(1+interest_rate,months))/(pow(1+interest_rate,months)-1);
    total_amount = monthly_payment*months;

    printf("\nYour monthly payment is: $%.2f\n", monthly_payment);
    printf("Your total payment for %d years will be: $%.2f\n", years, total_amount);

    return 0;
}