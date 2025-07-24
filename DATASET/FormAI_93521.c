//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: single-threaded
#include <stdio.h>

float calculateMonthlyPayment(float P, float r, float n);
float calculateTotalPayment(float monthlyPayment, float n);

int main() {
    float principal, rate, years;

    printf("Enter the principal amount: ");
    scanf("%f", &principal);

    printf("Enter the annual interest rate: ");
    scanf("%f", &rate);

    printf("Enter the number of years: ");
    scanf("%f", &years);

    // Convert annual rate into monthly rate
    float monthlyRate = (rate / 100.0) / 12.0;

    // Convert years into months
    float months = years * 12.0;

    // Calculate monthly payment
    float monthlyPayment = calculateMonthlyPayment(principal, monthlyRate, months);
    printf("Monthly Payment: %.2f\n", monthlyPayment);

    // Calculate total payment
    float totalPayment = calculateTotalPayment(monthlyPayment, months);
    printf("Total Payment: %.2f\n", totalPayment);

    return 0;
}

// Function to calculate monthly payment
float calculateMonthlyPayment(float P, float r, float n) {
    float numerator = r * P * pow((1 + r), n);
    float denominator = pow((1 + r), n) - 1.0;
    return numerator / denominator;
}

// Function to calculate total payment
float calculateTotalPayment(float monthlyPayment, float n) {
    return monthlyPayment * n;
}