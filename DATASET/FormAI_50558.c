//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: statistical
#include <stdio.h>
#include <math.h>

int main() {
    double loan_amount,interest_rate,monthly_payment;
    int num_years;
    
    //Input variables
    printf("Enter loan amount: ");
    scanf("%lf",&loan_amount);
    printf("Enter interest rate: ");
    scanf("%lf",&interest_rate);
    printf("Enter number of years: ");
    scanf("%d",&num_years);
    
    //Converting interest rate from percentage to decimal
    interest_rate = interest_rate/100.0;
    
    //Calculations to determine monthly payment
    double term = pow(1+interest_rate/12,num_years*12);
    monthly_payment = loan_amount*interest_rate/12.0*term/(term-1);
    
    //Output monthly payment
    printf("Monthly payment: %.2f\n",monthly_payment);
    
    return 0;
}