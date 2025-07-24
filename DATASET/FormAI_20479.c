//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: dynamic
#include<stdio.h>
#include<math.h>

// Function to calculate monthly mortgage payments
float calculateMonthlyPayments(float principal, float interest, int years) {
    float r = interest / 1200;
    int n = years * 12;
    float monthlyPayment = principal * r * pow(1 + r, n) / (pow(1 + r, n) - 1);
    return monthlyPayment;
}

int main() {
    float principal, interest;
    int years;
    
    // Get inputs from user
    printf("Enter principal amount: ");
    scanf("%f", &principal);
    
    printf("Enter interest rate (in percentage): ");
    scanf("%f", &interest);
    
    printf("Enter mortgage term (in years): ");
    scanf("%d", &years);
    
    // Calculate monthly mortgage payments
    float monthlyPayment = calculateMonthlyPayments(principal, interest, years);
    
    // Display results
    printf("\nLoan Summary:\n");
    printf("Principal Amount: %.2f\n", principal);
    printf("Interest Rate: %.2f%%\n", interest);
    printf("Number of Years: %d\n", years);
    printf("Monthly Payment: $%.2f\n", monthlyPayment);
    
    return 0;
}