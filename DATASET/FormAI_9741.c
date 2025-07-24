//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: detailed
#include <stdio.h>
#include <math.h>

// Function to calculate mortgage payment
double calculate_mortgage(double principal, double interest_rate, double years) {
    // Convert interest rate to monthly percentage and years to number of months
    double monthly_rate = interest_rate / 1200;
    double months = years * 12;
    
    // Calculate mortgage payment using formula
    double mortgage = (principal * monthly_rate) / (1 - pow(1 + monthly_rate, -months));
    return mortgage;
}

int main() {
    // Take input from user
    double principal, interest_rate, years;
    printf("Enter principal amount: ");
    scanf("%lf", &principal);
    printf("Enter interest rate: ");
    scanf("%lf", &interest_rate);
    printf("Enter number of years: ");
    scanf("%lf", &years);
    
    // Call function to calculate mortgage payment
    double mortgage = calculate_mortgage(principal, interest_rate, years);
    
    // Display output
    printf("Mortgage payment per month: $%.2lf\n", mortgage);
    
    return 0;
}