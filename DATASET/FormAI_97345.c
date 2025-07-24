//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Sherlock Holmes
#include <stdio.h>

// function to calculate mortgage payment
float mortgagePayment(float principle, float rate, int years) {
    float monthlyRate = rate / 1200.0;
    int months = years * 12;
    float payment = (principle * monthlyRate) / (1 - pow(1 + monthlyRate, -months));
    return payment;
}

int main() {
    float principle, rate;
    int years;
    
    // user inputs
    printf("Please enter the principle amount: ");
    scanf("%f", &principle);
    
    printf("Please enter the annual interest rate: ");
    scanf("%f", &rate);
    
    printf("Please enter the number of years for the mortgage: ");
    scanf("%d", &years);
    
    // calculation of monthly payment
    float payment = mortgagePayment(principle, rate, years);
    
    // output of results
    printf("\n---MORTGAGE CALCULATION---\n");
    printf("Principle Amount: $%.2f\n", principle);
    printf("Annual Interest Rate: %.2f%%\n", rate);
    printf("Number of Years: %d\n", years);
    printf("Monthly Payment: $%.2f\n", payment);
    printf("\n---END OF CALCULATION---\n");

    return 0;
}