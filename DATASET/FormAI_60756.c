//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// function for calculating the monthly payment
void calculate_monthly_payment(float loan_amount, float interest_rate, int loan_term_months) {
    float monthly_interest_rate = interest_rate / 100 / 12;
    float monthly_payment = (monthly_interest_rate * loan_amount) / (1 - pow((1 + monthly_interest_rate), (-1 * loan_term_months)));
    printf("Monthly Payment: $%.2f\n", monthly_payment);
}

// function for calculating the total amount paid
void calculate_total_amount_paid(float loan_amount, float interest_rate, int loan_term_months) {
    float monthly_interest_rate = interest_rate / 100 / 12;
    float monthly_payment = (monthly_interest_rate * loan_amount) / (1 - pow((1 + monthly_interest_rate), (-1 * loan_term_months)));
    float total_amount_paid = monthly_payment * loan_term_months;
    printf("Total Amount Paid: $%.2f\n", total_amount_paid);
}

// function for calculating the total interest paid
void calculate_total_interest_paid(float loan_amount, float interest_rate, int loan_term_months) {
    float monthly_interest_rate = interest_rate / 100 / 12;
    float monthly_payment = (monthly_interest_rate * loan_amount) / (1 - pow((1 + monthly_interest_rate), (-1 * loan_term_months)));
    float total_interest_paid = monthly_payment * loan_term_months - loan_amount;
    printf("Total Interest Paid: $%.2f\n", total_interest_paid);
}

int main() {
    float loan_amount, interest_rate;
    int loan_term_years;
    
    printf("Enter Loan Amount: ");
    scanf("%f", &loan_amount);
    
    printf("Enter Interest Rate: ");
    scanf("%f", &interest_rate);
    
    printf("Enter Loan Term (in years): ");
    scanf("%d", &loan_term_years);
    
    int loan_term_months = loan_term_years * 12;
    
    printf("\n");
    calculate_monthly_payment(loan_amount, interest_rate, loan_term_months);
    calculate_total_amount_paid(loan_amount, interest_rate, loan_term_months);
    calculate_total_interest_paid(loan_amount, interest_rate, loan_term_months);
    
    return 0;
}