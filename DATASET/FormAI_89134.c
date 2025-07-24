//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: careful
#include <stdio.h> 

// Function to calculate yearly returns on investment 
double calculateReturns(double investment, double roi) { 
    return investment * roi / 100; 
} 

// Function to calculate monthly EMI on a loan 
double calculateEMI(double principal, double roi, int term) { 
    double r = roi / (12 * 100); // monthly interest rate 
    int n = term * 12; // total number of payments 
    return (principal * r) / (1 - pow(1 + r, -n)); 
} 

// Main function 
int main() { 
    double investment, roi, principal; 
    int term; 

    // Input for investment details 
    printf("Enter your investment amount: "); 
    scanf("%lf", &investment); 
    printf("Enter expected rate of return: "); 
    scanf("%lf", &roi); 

    double yearlyReturns = calculateReturns(investment, roi); 
    printf("\nYearly Returns: %.2lf", yearlyReturns); 

    // Input for loan details 
    printf("\nEnter loan principal amount: "); 
    scanf("%lf", &principal); 
    printf("Enter rate of interest: "); 
    scanf("%lf", &roi); 
    printf("Enter loan term (in years): "); 
    scanf("%d", &term); 

    double emi = calculateEMI(principal, roi, term); 
    printf("\nMonthly EMI: %.2lf", emi); 

    return 0; 
}