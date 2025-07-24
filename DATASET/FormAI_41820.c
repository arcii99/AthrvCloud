//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: happy
#include<stdio.h>

int main()
{
    printf("\n\n\t\t******Welcome to the Happy Mortgage Calculator******\n\n\n");
    float principal,interest_rate,monthly_payment,total_interest;
    int no_of_months,years;

    //Taking user input
    printf("Enter the Principal amount: ");
    scanf("%f",&principal);
    printf("Enter the Number of years to payoff the Mortgage: ");
    scanf("%d",&years);
    printf("Enter the Annual Interest Rate for the Mortgage: ");
    scanf("%f",&interest_rate);

    //Converting years into months
    no_of_months = years * 12;

    //Calculating monthly payment and total interest
    interest_rate = interest_rate / (12*100);
    float x = pow(1 + interest_rate, no_of_months);
    monthly_payment = (principal*x*interest_rate)/(x-1);
    total_interest = monthly_payment * no_of_months - principal;

    //Displaying the results
    printf("\n\n\t\t******Happy Mortgage Payment Details****** \n\n\n");
    printf("Principal Amount: %0.2f\n",principal);
    printf("Payment Term: %d years\n",years);
    printf("Total amount of Interest: %0.2f\n",total_interest);
    printf("Monthly Payment: %0.2f\n",monthly_payment);
    printf("\n\n\t\t******Thank you for using our confident Mortgage Calculator******\n\n");

    return 0;
}