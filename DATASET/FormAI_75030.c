//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* Function to calculate compound interest */
double compound_interest(double principal, double rate, double time) {
    double interest = principal * pow((1 + rate / 100.0), time);
    return interest;
}

/* Function to calculate the future value of the investment */
double calculate_future_value(double principal, double rate, double time) {
    double future_value = principal * (pow(1 + rate/100.0, time));
    return future_value;
}

/* Function to print the investment summary */
void print_summary(double principal, double rate, double time, double future_value, double interest_amt) {
    printf("\n\n********* Investment Summary *********\n\n");
    printf("Initial Investment : $%.2lf\n", principal);
    printf("Annual Interest Rate : %.2lf%%\n", rate);
    printf("Investment Time (in years) : %.2lf\n", time);
    printf("Future Value : $%.2lf\n", future_value);
    printf("Interest Earned : $%.2lf\n", interest_amt);
}

int main() {
    double principal = 0;
    double annual_interest_rate = 0;
    double investment_time = 0;
    double interest_amt = 0;
    double future_value = 0;
    
    /* Getting input from user */
    printf("Enter the Principal Amount : ");
    scanf("%lf", &principal);
    printf("Enter the Annual Interest rate : ");
    scanf("%lf", &annual_interest_rate);
    printf("Enter the Investment Time (in years) : ");
    scanf("%lf", &investment_time);

    /* Calculating future value and interest after given investment time */
    future_value = calculate_future_value(principal, annual_interest_rate, investment_time);
    interest_amt = future_value - principal;

    /* Printing the investment summary */
    print_summary(principal, annual_interest_rate, investment_time, future_value, interest_amt);
    return 0;
}