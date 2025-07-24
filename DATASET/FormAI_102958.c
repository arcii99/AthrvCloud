//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: peaceful
#include<stdio.h>
#include<math.h>

int main() {
    float loanAmount, rateOfInterest, monthlyPayment, totalPayment, monthlyInterest;
    int numberOfYears, numberOfMonths;
    
    printf("Welcome to the peaceful Mortgage Calculator\n\n");
    
    printf("Enter the loan amount: ");
    scanf("%f", &loanAmount);
    
    printf("Enter the rate of interest: ");
    scanf("%f", &rateOfInterest);
    
    printf("Enter the number of years: ");
    scanf("%d", &numberOfYears);
    
    numberOfMonths = numberOfYears * 12;
    monthlyInterest = rateOfInterest / 1200; // 12 months/year and 100% interest
    
    // Calculation
    monthlyPayment = loanAmount * monthlyInterest * pow((1 + monthlyInterest), numberOfMonths) / (pow((1 + monthlyInterest), numberOfMonths) - 1);
    totalPayment = monthlyPayment * numberOfMonths;
    
    printf("\nMonthly Payment: $%.2f\n", monthlyPayment);
    printf("Total Payment: $%.2f\n\n", totalPayment);
    
    return 0;
}