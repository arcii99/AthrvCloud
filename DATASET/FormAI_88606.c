//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: optimized
#include<stdio.h>
#include<math.h>

// Function to calculate the mortgage payment
float calculatePayment(float principal, float rate, int years, int paymentsPerYear);

int main() {
    // Variables
    float principal, rate;
    int years, paymentsPerYear;

    // Taking inputs
    printf("Enter the principal amount: ");
    scanf("%f", &principal);

    printf("Enter the interest rate (percentage): ");
    scanf("%f", &rate);

    printf("Enter number of years: ");
    scanf("%d", &years);

    printf("Enter number of payments per year: ");
    scanf("%d", &paymentsPerYear);

    // Calculating the mortgage payment
    float payment = calculatePayment(principal, rate, years, paymentsPerYear);

    // Displaying the result
    printf("Mortgage payment: $%.2f\n", payment);

    return 0;
}

float calculatePayment(float principal, float rate, int years, int paymentsPerYear) {
    float r = rate / 100 / paymentsPerYear;    // monthly interest rate
    float n = years * paymentsPerYear;      // number of payments

    // calculating the payment
    float payment = (principal*r*(pow(1+r,n)))/(pow(1+r,n)-1);

    return payment;
}