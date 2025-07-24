//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: grateful
#include <stdio.h>
#include <math.h>

int main(){
    float amount, rate, years;
    float monthly_i, monthly_payment, total_payment;

    printf("Welcome to the Mortgage Calculator Program!\n");

    printf("Please enter the principal amount in dollars: ");
    scanf("%f", &amount);

    printf("Please enter the interest rate: ");
    scanf("%f", &rate);

    printf("Please enter the number of years for the mortgage: ");
    scanf("%f", &years);

    // convert yearly interest rate into monthly interest rate
    monthly_i = rate / 1200;

    // calculate monthly payment
    monthly_payment = (amount * monthly_i) / (1 - pow(1 + monthly_i, -(years * 12)));
    printf("\nThe monthly payment is $%.2f\n", monthly_payment);

    // calculate total payment
    total_payment = monthly_payment * years * 12;
    printf("The total payment is $%.2f\n", total_payment);

    printf("Thank you for using the Mortgage Calculator Program!\n");

    return 0;
}