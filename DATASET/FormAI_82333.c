//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: calm
#include<stdio.h>
#include<math.h>

int main(){

    float principal,interest_rate,monthly_interest_rate,mortgage_years,payment_month,Total_Payment,mortgage;

    printf("Welcome to Mortgage Calculator!\n");
    printf("Enter the amount of your mortgage: \n");
    scanf("%f",&principal);
    printf("Enter the interest rate (per year) : \n");
    scanf("%f",&interest_rate);
    printf("Enter the years of mortgage: \n");
    scanf("%f",&mortgage_years);

    monthly_interest_rate = interest_rate/12.0;

    payment_month = 12.0 * mortgage_years;

    mortgage = principal * (monthly_interest_rate/(1.0-pow(1.0+monthly_interest_rate,-payment_month)));

    Total_Payment = mortgage * payment_month;

    printf("Your monthly payment is: $%.2f \n", mortgage);
    printf("Your total payment is: $%.2f \n", Total_Payment);

    return 0;
}