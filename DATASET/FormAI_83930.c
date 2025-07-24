//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: configurable
#include<stdio.h>

float calculateMonthlyPayment(float loan, float interest, int term);
float calculateTotalPayment(float monthlyPayment, int term);

int main(){

    float loan, interest, monthlyPayment, totalPayment;
    int term;

    printf("Enter the loan amount: $");
    scanf("%f", &loan);

    printf("Enter the annual interest rate: ");
    scanf("%f", &interest);

    printf("Enter the loan term (in years): ");
    scanf("%d", &term);

    monthlyPayment = calculateMonthlyPayment(loan, interest, term);
    totalPayment = calculateTotalPayment(monthlyPayment, term);

    printf("\nMonthly Payment: $%.2f\n", monthlyPayment);
    printf("Total Payment: $%.2f\n", totalPayment);

    return 0;
}

float calculateMonthlyPayment(float loan, float interest, int term){

    float monthlyInterestRate = interest/1200;
    float temp = pow((1+monthlyInterestRate), term*12);
    float monthlyPayment = (loan*monthlyInterestRate*temp)/(temp-1);

    return monthlyPayment;
}

float calculateTotalPayment(float monthlyPayment, int term){

    float totalPayment = monthlyPayment*term*12;

    return totalPayment;

}