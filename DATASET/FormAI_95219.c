//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Define constants
#define PRINCIPAL_MIN 10000
#define PRINCIPAL_MAX 1000000
#define INTEREST_MIN 0.1
#define INTEREST_MAX 30
#define TERM_MIN 1
#define TERM_MAX 30

// Function to calculate mortgage
float calculate_mortgage(float principal, float interest, float term) {
    float monthly_interest = interest / 1200;  // Calculate monthly interest
    float num_payments = term * 12;  // Calculate total number of payments
    float mortgage = (principal * monthly_interest) / (1 - pow(1 + monthly_interest, -num_payments));  // Calculate mortgage
    return mortgage;
}

int main() {
    // Declare variables
    float principal, interest, term, mortgage;
    
    // Get input from user
    printf("Enter principal amount ($%d - $%d): ", PRINCIPAL_MIN, PRINCIPAL_MAX);
    scanf("%f", &principal);
    if (principal < PRINCIPAL_MIN || principal > PRINCIPAL_MAX) {
        printf("Error: Principal amount must be between $%d and $%d.\n", PRINCIPAL_MIN, PRINCIPAL_MAX);
        return 1;
    }
    
    printf("Enter interest rate (%g%% - %g%%): ", INTEREST_MIN, INTEREST_MAX);
    scanf("%f", &interest);
    if (interest < INTEREST_MIN || interest > INTEREST_MAX) {
        printf("Error: Interest rate must be between %g%% and %g%%.\n", INTEREST_MIN, INTEREST_MAX);
        return 1;
    }
    
    printf("Enter mortgage term (years) (%d - %d): ", TERM_MIN, TERM_MAX);
    scanf("%f", &term);
    if (term < TERM_MIN || term > TERM_MAX)  {
        printf("Error: Mortgage term must be between %d and %d years.\n", TERM_MIN, TERM_MAX);
        return 1;
    }
    
    // Calculate mortgage
    mortgage = calculate_mortgage(principal, interest, term);
    
    // Display results
    printf("\n\nMortgage Payment Calculator\n");
    printf("===========================\n");
    printf("Principal Amount: $%.2f\n", principal);
    printf("Interest Rate: %.2f%%\n", interest);
    printf("Mortgage Term (years): %.0f\n", term);
    printf("Monthly Mortgage Payment: $%.2f\n", mortgage);
    
    return 0;
}