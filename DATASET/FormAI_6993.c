//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: synchronous
#include<stdio.h>
#include<math.h>

int main() {
    // Initialization of variables
    double principle, interest_rate, time, monthly_interest, monthly_payment;
    int months;

    // Taking inputs from the user
    printf("Enter the principle amount of the mortgage: ");
    scanf("%lf",&principle);

    printf("Enter the interest rate (in percentage): ");
    scanf("%lf",&interest_rate);

    printf("Enter the time period of the mortgage (in years): ");
    scanf("%lf",&time);

    // Calculating the monthly interest rate and the number of months
    monthly_interest = interest_rate/(12*100);    
    months = time*12;

    // Calculating the monthly payment
    monthly_payment = (principle*monthly_interest*pow((1+monthly_interest),months))/(pow((1+monthly_interest),months)-1);

    // Displaying the monthly payment
    printf("\nThe monthly payment for the mortgage is: $%.2lf\n", monthly_payment);

    return 0;
}