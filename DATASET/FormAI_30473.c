//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double loan_amount, interest_rate, monthly_rate, num_years, num_months, monthly_payment, total_interest, total_amount_paid;
    
    // User Input
    printf("Enter Loan Amount: $");
    scanf("%lf", &loan_amount);
    
    printf("Enter Interest Rate (in percentage): ");
    scanf("%lf", &interest_rate);
    monthly_rate = (interest_rate/100)/12;
    
    printf("Enter Loan Period (in years): ");
    scanf("%lf", &num_years);
    num_months = num_years*12;
    
    // Calculation
    monthly_payment = (loan_amount * monthly_rate * pow(1+monthly_rate, num_months)) / (pow(1+monthly_rate, num_months) - 1);
    total_amount_paid = monthly_payment * num_months;
    total_interest = total_amount_paid - loan_amount;
    
    // Output
    printf("\nMonthly Payment: $%.2lf\n", monthly_payment);
    printf("Total Interest: $%.2lf\n", total_interest);
    printf("Total Amount Paid: $%.2lf\n", total_amount_paid);
    
    return 0;
}