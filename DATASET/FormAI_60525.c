//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//function to calculate monthly payment
double get_monthly_payment(double principal, double interest_rate, double years) {
    double rate = interest_rate / 1200;
    double num_payments = years * 12;
    double monthly_payment = (principal * rate) / (1 - pow(1 + rate, -num_payments));
    return monthly_payment;
}

int main() {
    //variable declarations
    double principal, interest_rate, years, monthly_payment;
    
    //get input from the user
    printf("Enter the principal amount: ");
    scanf("%lf", &principal);
    printf("Enter the interest rate: ");
    scanf("%lf", &interest_rate);
    printf("Enter the duration of the loan in years: ");
    scanf("%lf", &years);
    
    //calculate the monthly payment
    monthly_payment = get_monthly_payment(principal, interest_rate, years);
    printf("Your monthly payment is: $%.2lf\n", monthly_payment);
    
    return 0;
}