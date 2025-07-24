//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: protected
#include<stdio.h>
#include<math.h>

int main() {
    float principal; 
    float interest_rate; 
    int term; 
    float EMI; 

    printf("Enter the principal amount:\n");
    scanf("%f", &principal);

    printf("Enter the interest rate:\n");
    scanf("%f", &interest_rate);

    printf("Enter the term (in years):\n");
    scanf("%d", &term);

    interest_rate = interest_rate / 12;  // Calculating the monthly interest rate
    term = term * 12;  // Converting the term from years to months

    // Calculating the EMI value
    EMI = (principal * interest_rate * pow(1 + interest_rate, term)) / (pow(1 + interest_rate, term) - 1);

    printf("The EMI amount is: %.2f\n", EMI);

    return 0;
}