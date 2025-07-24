//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: multivariable
#include <stdio.h>

// Function to calculate monthly loan payments
float loanPayment(float principle, float interest, int months) {
    float r = interest/1200;
    float payment = (principle * r) / (1 - pow(1+r, -months));
    return payment;
}

// Function to calculate compound interest
float compoundInterest(float principle, float interest, int years) {
    float r = interest/100;
    float A = principle * pow(1+r, years);
    return A;
}

// Function to calculate simple interest
float simpleInterest(float principle, float interest, int years) {
    float r = interest/100;
    float A = principle * (1 + (r * years));
    return A;
}

int main() {
    // Variables for user input
    float principle, interest;
    int months, years;

    // Prompt user for input
    printf("Enter the principle amount: $");
    scanf("%f", &principle);
    printf("Enter the interest rate: ");
    scanf("%f", &interest);
    printf("Enter the loan term in months (set to 0 for savings calculations): ");
    scanf("%d", &months);
    printf("Enter the investment term in years (set to 0 for loan calculations): ");
    scanf("%d", &years);

    // Calculate loan payment if applicable
    if (months > 0) {
        float payment = loanPayment(principle, interest, months);
        printf("Your monthly loan payment is: $%.2f\n", payment);
    }
    // Calculate future savings if applicable
    if (years > 0) {
        float simple = simpleInterest(principle, interest, years);
        float compound = compoundInterest(principle, interest, years);
        printf("Your savings with simple interest will be: $%.2f\n", simple);
        printf("Your savings with compound interest will be: $%.2f\n", compound);
    }

    return 0;
}